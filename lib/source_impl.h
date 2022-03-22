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

#ifndef INCLUDED_PIPE_SOURCE_IMPL_H
#define INCLUDED_PIPE_SOURCE_IMPL_H

#include <stdio.h>

#include <gnuradio/pipe/source.h>

namespace gr {
  namespace pipe {

    class source_impl : public source
    {
     private:
      size_t d_out_item_sz;

      // Runtime data
      int d_cmd_stdout_pipe[2];
      FILE *d_cmd_stdout;
      pid_t d_cmd_pid;

      void create_command_process(const char *cmd);
      void create_pipe(int pipe[2]);
      void set_fd_flags(int fd, long flags);
      void reset_fd_flags(int fd, long flags);
      int  read_process_output(uint8_t *out, int nitems);

     public:
      source_impl(size_t out_item_sz, const char *cmd);
      ~source_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace pipe
} // namespace gr

#endif /* INCLUDED_PIPE_SOURCE_IMPL_H */

