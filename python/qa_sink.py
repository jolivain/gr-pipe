#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2020 Julien Olivain <juju@cotds.org>.
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
import os
import time

class qa_sink(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        test_str = "Hello GNU Radio"
        filename = "/tmp/test_003_pipe_sink." + str(os.getpid())
        src_data = tuple(map(lambda x: ord(x), list(test_str)))
        src = blocks.vector_source_b (src_data)
        pipe_sink = pipe.sink(gr.sizeof_char, "cat > " + filename)
        pipe_sink.set_unbuffered(True)
        self.tb.connect (src, pipe_sink)
        self.tb.run ()
        time.sleep(0.1)
        with open(filename, "r") as f:
            out_data = f.read()
        os.unlink(filename)
        self.assertEqual (test_str, out_data)


if __name__ == '__main__':
    gr_unittest.run(qa_sink)
