/* -*- c++ -*- */
/*
 * Copyright 2012-2020 Julien Olivain <ju.o@free.fr>.
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

#include <gnuradio/pipe/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace pipe {

    /*!
     * \brief gr-pipe is a set of blocks for using any program as a
     * source, sink or filter by using standard I/O pipes.
     *
     * \ingroup pipe
     */
    class PIPE_API filter : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<filter> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pipe::filter.
       *
       * To avoid accidental use of raw pointers, pipe::filter's
       * constructor is in a private implementation
       * class. pipe::filter::make is the public interface for
       * creating new instances.
       */
      static sptr make(size_t in_item_sz, size_t out_item_sz, double relative_rate, const char *cmd);

      virtual bool unbuffered () const = 0;
      virtual void set_unbuffered (bool unbuffered) = 0;
    };

  } // namespace pipe
} // namespace gr

#endif /* INCLUDED_PIPE_FILTER_H */
