#! /usr/bin/env python

"""
Generate test data.

    Usage:

        test_data_gen.py [start] [stop] [step]

    Usage example:

        ./test_data_gen.py 0. 1. 1.
        ./test_data_gen.py -1 1 0.1
"""

import struct
import sys

def gen_data(out, start, stop, step):
    """
    Generates native float data from start, to stop, by step
    increments.  data is written on out.
    """
    count = int((stop - start) / step)
    val = start
    for _ in range(count):
        outdata = struct.pack("=f", val)
        out.write(outdata)
        val += step

def main(argv):
    """
    Main function.
    """
    if len(argv) >= 2:
        start = float(argv[1])
    else:
        start = 0.

    if len(argv) >= 3:
        stop = float(argv[2])
    else:
        stop = start + 10.

    if len(argv) >= 4:
        step = float(argv[3])
    else:
        step = 1.

    gen_data(sys.stdout.buffer, start, stop, step)


if __name__ == "__main__":
    main(sys.argv)
