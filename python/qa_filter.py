#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 Julien Olivain <ju.o@free.fr>.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import pipe_swig as pipe
import time

class qa_filter(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        test_str = "Hello GNU Radio!"
        src_data = tuple(map(lambda x: ord(x), list(test_str)))
        expected_result = tuple(map(lambda x: ord(x), list(test_str.upper())))
        src = blocks.vector_source_b (src_data, True)
        pipe_filter = pipe.filter(gr.sizeof_char, gr.sizeof_char, 1.0, "tr a-z A-Z")
        head = blocks.head(gr.sizeof_char, len(test_str))
        dst = blocks.vector_sink_b ()
        self.tb.connect (src, pipe_filter, head, dst)
        self.tb.run ()
        time.sleep(0.1)
        result_data = dst.data ()
        self.assertEqual (expected_result, result_data)


if __name__ == '__main__':
    gr_unittest.run(qa_filter)
