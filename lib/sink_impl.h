/* -*- c++ -*- */
/*
 * Copyright 2020 Julien Olivain <juju@cotds.org>.
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

#ifndef INCLUDED_PIPE_SINK_IMPL_H
#define INCLUDED_PIPE_SINK_IMPL_H

#include <stdio.h>
#include <gnuradio/pipe/sink.h>

namespace gr {
  namespace pipe {

    class sink_impl : public sink
    {
     private:
      size_t d_in_item_sz;
      bool   d_unbuffered;

      // Runtime data
      int d_cmd_stdin_pipe[2];
      FILE *d_cmd_stdin;
      pid_t d_cmd_pid;

      void create_command_process(const char *cmd);
      void create_pipe(int pipe[2]);
      void set_fd_flags(int fd, long flags);
      void reset_fd_flags(int fd, long flags);
      int write_process_input(const uint8_t *in, int nitems);


     public:
      sink_impl(size_t in_item_sz, const char *cmd);
      ~sink_impl();

      bool unbuffered () const;
      void set_unbuffered (bool unbuffered);

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace pipe
} // namespace gr

#endif /* INCLUDED_PIPE_SINK_IMPL_H */

