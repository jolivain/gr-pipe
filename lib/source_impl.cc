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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

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


    /*
     * The private constructor
     */
    source_impl::source_impl(size_t out_item_sz, const char *cmd)
      : gr::sync_block("source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(<+MIN_OUT+>, <+MAX_OUT+>, sizeof(<+OTYPE+>)))
    {}

    /*
     * Our virtual destructor.
     */
    source_impl::~source_impl()
    {
    }

    int
    source_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      <+OTYPE+> *out = (<+OTYPE+> *) output_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pipe */
} /* namespace gr */

