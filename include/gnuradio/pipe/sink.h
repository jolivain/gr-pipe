/* -*- c++ -*- */
/*
 * Copyright 2020 Julien Olivain <ju.o@free.fr>.
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

#ifndef INCLUDED_PIPE_SINK_H
#define INCLUDED_PIPE_SINK_H

#include <gnuradio/pipe/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace pipe {

    /*!
     * \brief <+description of block+>
     * \ingroup pipe
     *
     */
    class PIPE_API sink : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<sink> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pipe::sink.
       *
       * To avoid accidental use of raw pointers, pipe::sink's
       * constructor is in a private implementation
       * class. pipe::sink::make is the public interface for
       * creating new instances.
       */
      static sptr make(size_t in_item_sz, const char *cmd);

      virtual bool unbuffered () const = 0;
      virtual void set_unbuffered (bool unbuffered) = 0;
    };

  } // namespace pipe
} // namespace gr

#endif /* INCLUDED_PIPE_SINK_H */

