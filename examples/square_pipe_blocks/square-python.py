#! /usr/bin/env python

import struct
import sys

while True:
    data = sys.stdin.read(4)
    if len(data) == 0:
        break
    elif len(data) == 4:
        (val,) = struct.unpack("=f", data)
        #print >> sys.stderr, val
        outdata = struct.pack("=f", val * val)
        sys.stdout.write(outdata)
    else:
        print >> sys.stderr, "# could not read a float32 (wanted 4 bytes, got", len(data), ")"
