#! /usr/bin/env python3
#
# Execute with:
#   python3 square-python.py
#

import struct
import sys

DATA_FORMAT = "=f"
DATA_LEN = struct.calcsize(DATA_FORMAT)

while True:
    data = sys.stdin.buffer.read(DATA_LEN)
    if len(data) == 0:
        break
    elif len(data) == DATA_LEN:
        (val,) = struct.unpack(DATA_FORMAT, data)
        # print(val, file=sys.stderr)
        outdata = struct.pack(DATA_FORMAT, val * val)
        sys.stdout.buffer.write(outdata)
    else:
        print("# could not read a float (wanted", DATA_LEN, "bytes, got", len(data), ")", file=sys.stderr)
