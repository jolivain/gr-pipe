#! /usr/bin/env Rscript

# Default stdin connection is text.
# We need it to be binary to use readBin()
i = file("stdin", "rb")

# file() does not recognize "stdout" as a special file. It's creating
# a file named "stdout" instead.  It's also not possible to use
# stdout() because the connection is text.  It' also not possible to
# change the stdout() connection as binary.  We open the /dev/stdout
# raw file.  This will work on Linux, but it's not portable to other
# systems.
o = file("/dev/stdout", "wb", raw=TRUE)

while (TRUE) {
    val = readBin(i, "double", 1, size=4)

    if (length(val) == 0) break

    res = val * val

    # print(res)

    writeBin(res, con=o, size=4)
}
