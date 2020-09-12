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

#ifndef INCLUDED_PIPE_FILTER_H
#define INCLUDED_PIPE_FILTER_H

#include <pipe/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace pipe {

    /*!
     * \brief <+description of block+>
     * \ingroup pipe
     *
     */
    class PIPE_API filter : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<filter> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pipe::filter.
       *
       * To avoid accidental use of raw pointers, pipe::filter's
       * constructor is in a private implementation
       * class. pipe::filter::make is the public interface for
       * creating new instances.
       */
      static sptr make(size_t in_item_sz, size_t out_item_sz, double relative_rate, const char *cmd);
    };

  } // namespace pipe
} // namespace gr

#endif /* INCLUDED_PIPE_FILTER_H */

