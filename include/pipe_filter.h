/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_PIPE_FILTER_H
#define INCLUDED_PIPE_FILTER_H

#include <pipe_api.h>
#include <gr_block.h>

class pipe_filter;

/*
 * We use boost::shared_ptr's instead of raw pointers for all access
 * to gr_blocks (and many other data structures).  The shared_ptr gets
 * us transparent reference counting, which greatly simplifies storage
 * management issues.  This is especially helpful in our hybrid
 * C++ / Python system.
 *
 * See http://www.boost.org/libs/smart_ptr/smart_ptr.htm
 *
 * As a convention, the _sptr suffix indicates a boost::shared_ptr
 */
typedef boost::shared_ptr<pipe_filter> pipe_filter_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of pipe_filter.
 *
 * To avoid accidental use of raw pointers, pipe_filter's
 * constructor is private.  chaos_make_dcsk_mod_cbc is the public
 * interface for creating new instances.
 */
PIPE_API pipe_filter_sptr pipe_make_filter (size_t in_item_sz,
                                            size_t out_item_sz,
                                            double relative_rate,
                                            const char *cmd);

/*!
 * Create a filter block with any program connected through pipe.
 * \ingroup block
 *
 * This uses the preferred technique: subclassing gr_block.
 */
class PIPE_API pipe_filter : public gr_block
{
private:
  // The friend declaration allows pipe_make_filter to
  // access the private constructor.

  friend PIPE_API pipe_filter_sptr pipe_make_filter (size_t in_item_sz,
                                                     size_t out_item_sz,
                                                     double relative_rate,
                                                     const char *cmd);

  size_t d_in_item_sz;
  size_t d_out_item_sz;
  double d_relative_rate;

  // Runtime data
  int d_cmd_stdin_pipe[2];
  int d_cmd_stdout_pipe[2];
  pid_t d_cmd_pid;

  pipe_filter (size_t in_item_sz,
               size_t out_item_sz,
               double relative_rate,
               const char *cmd);  	// private constructor

  void create_command_process(const char *cmd);
  void create_pipe(int pipe[2]);
  void set_fd_flags(int fd, long flags);
  void reset_fd_flags(int fd, long flags);
  int read_process_output(uint8_t *out, int nitems);
  void write_process_input(const uint8_t *in, int nitems);

public:
  ~pipe_filter ();	// public destructor

  void forecast (int noutput_items, gr_vector_int &ninput_items_required);
  
  // Where all the action really happens

  int general_work (int noutput_items,
		    gr_vector_int &ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_PIPE_FILTER_H */
