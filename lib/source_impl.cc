/* -*- c++ -*- */
/*
 * Copyright 2012-2020 Julien Olivain <juju@cotds.org>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

#include <iostream>

#include <gnuradio/io_signature.h>
#include "source_impl.h"

namespace gr {
  namespace pipe {

    source::sptr
    source::make(size_t out_item_sz, const char *cmd)
    {
      return gnuradio::get_initial_sptr
        (new source_impl(out_item_sz, cmd));
    }

    static const int MIN_IN = 0;     // mininum number of input streams
    static const int MAX_IN = 0;     // maximum number of input streams
    static const int MIN_OUT = 1;    // minimum number of output streams
    static const int MAX_OUT = 1;    // maximum number of output streams

    /*
     * The private constructor
     */
    source_impl::source_impl(size_t out_item_sz, const char *cmd)
      : gr::sync_block("source",
              gr::io_signature::make(MIN_IN, MAX_IN, 0),
              gr::io_signature::make(MIN_OUT, MAX_OUT, out_item_sz)),
        d_out_item_sz (out_item_sz)
    {
      create_command_process(cmd);
    }

    /*
     * Our virtual destructor.
     */
    source_impl::~source_impl()
    {
      long ret;
      int pstat;

      fclose(d_cmd_stdout);

      kill(d_cmd_pid, SIGTERM);

      do {
        ret = waitpid(d_cmd_pid, &pstat, 0);
      } while (ret == -1 && errno == EINTR);

      if (ret == -1) {
        perror("waitpid()");
        return ;
      }

      if (WIFEXITED(pstat)) {
        std::cerr << "Process exited with code " << WEXITSTATUS(pstat) << std::endl;
      }
      else if (WIFSIGNALED(pstat)) {
        if (WTERMSIG(pstat) != SIGTERM)
          std::cerr << "Process exited with signal " << WTERMSIG(pstat) << std::endl;
      }
      else {
        std::cerr << "Abnormal process termination" << std::endl;
      }
    }

    void
    source_impl::create_pipe(int pipefd[2])
    {
      int ret;

      ret = ::pipe(pipefd);
      if (ret != 0) {
          perror("pipe()");
          throw std::runtime_error("pipe() error");
      }
    }

    void
    source_impl::create_command_process(const char *cmd)
    {
      create_pipe(d_cmd_stdout_pipe);

      d_cmd_pid = fork();
      if (d_cmd_pid == -1) {
          perror("fork()");
          return ;
      }
      else if (d_cmd_pid == 0) {
        dup2(d_cmd_stdout_pipe[1], STDOUT_FILENO);
        close(d_cmd_stdout_pipe[1]);
        close(d_cmd_stdout_pipe[0]);

        execl("/bin/sh", "sh", "-c", cmd, NULL);

        perror("execl()");
        exit(EXIT_FAILURE);
      }
      else {
        close(d_cmd_stdout_pipe[1]);

        fcntl(d_cmd_stdout_pipe[0], F_SETFD, FD_CLOEXEC);

        d_cmd_stdout = fdopen(d_cmd_stdout_pipe[0], "r");
        if (d_cmd_stdout == NULL) {
          perror("fdopen()");
          throw std::runtime_error("fdopen() error");
          return ;
        }
      }
    }

    int
    source_impl::read_process_output(uint8_t *out, int nitems)
    {
      size_t ret;

      ret = fread(out, d_out_item_sz, nitems, d_cmd_stdout);
      if (    ret == 0
           && ferror(d_cmd_stdout)
           && errno != EAGAIN
           && errno != EWOULDBLOCK) {
        throw std::runtime_error("fread() error");
        return (-1);
      }

      return (ret);
    }

    int
    source_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      uint8_t *out = (uint8_t *) output_items[0];
      int n_produced;

      n_produced = read_process_output(out, noutput_items);

      return noutput_items;
    }

  } /* namespace pipe */
} /* namespace gr */
