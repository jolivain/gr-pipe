#!/usr/bin/env python
#
# Copyright 2004,2007 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
import os, time
import pipe_python

class qa_pipe (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_pipe_source (self):
        test_str = "Hello GNU Radio"
        expected_result = tuple(map(lambda x: long(ord(x)), list(test_str)))
        pipe_source = pipe_swig.source(gr.sizeof_char, "echo -n " + test_str)
        dst = gr.vector_sink_b ()
        self.tb.connect (pipe_source, dst)
        self.tb.run ()
        result_data = dst.data ()
        self.assertEqual (expected_result, result_data)

    # def test_002_pipe_filter (self):
    #     test_str = "Hello GNU Radio!"
    #     src_data = map(lambda x: ord(x), list(test_str))
    #     expected_result = tuple(map(lambda x: long(ord(x)), list(test_str.upper())))
    #     src = gr.vector_source_b (src_data, True)
    #     pipe_filter = pipe_swig.filter(gr.sizeof_char, gr.sizeof_char, 1.0, "tr a-z A-Z")
    #     head = gr.head(gr.sizeof_char, len(test_str))
    #     dst = gr.vector_sink_b ()
    #     self.tb.connect (src, pipe_filter, head, dst)
    #     self.tb.run () 
    #     result_data = dst.data ()
    #     self.assertEqual (expected_result, result_data)

    def test_003_pipe_sink (self):
        test_str = "Hello GNU Radio"
        filename = "/tmp/test_003_pipe_sink." + str(os.getpid())
        src_data = map(lambda x: ord(x), list(test_str))
        src = gr.vector_source_b (src_data)
        pipe_sink = pipe_swig.sink(gr.sizeof_char, "cat > " + filename)
        self.tb.connect (src, pipe_sink)
        self.tb.run ()
        time.sleep(1)
        out_data = open(filename, "r").read()
        self.assertEqual (test_str, out_data)
        os.unlink(filename)

if __name__ == '__main__':
    gr_unittest.main ()
