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
#include "filter_impl.h"

namespace gr {
  namespace pipe {

    filter::sptr
    filter::make(size_t in_item_sz, size_t out_item_sz, double relative_rate, const char *cmd)
    {
      return gnuradio::get_initial_sptr
        (new filter_impl(in_item_sz, out_item_sz, relative_rate, cmd));
    }


    /*
     * The private constructor
     */
    filter_impl::filter_impl(size_t in_item_sz, size_t out_item_sz, double relative_rate, const char *cmd)
      : gr::block("filter",
              gr::io_signature::make(1, 1, in_item_sz),
              gr::io_signature::make(1, 1, out_item_sz))
    {}

    /*
     * Our virtual destructor.
     */
    filter_impl::~filter_impl()
    {
    }

    void
    filter_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    filter_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];

      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pipe */
} /* namespace gr */

