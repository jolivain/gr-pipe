# gr-pipe GNU Radio blocks #

gr-pipe is a set GNU Radio block for using any program as a source,
sink or filter by using standard I/O pipes.

## Introduction ##

The main goals of these blocks are:

* Fast development of new experimental blocks (no need to dig into C++
  / GNU Radio internals / SWIG / Python).
* Ability to use any programming language able to deal with standard
  input and output (code a block in your preferred language: C, Java,
  MatLab, Perl, Ruby...).

Simple interface:

The gr-pipe blocks read and write samples sequentially in their GNU
Radio internal representation. The format is the same as for
gr_file_source and gr_file_sink:

| GNU Radio type name | C Type             | size                               |
| ------------------- | ------------------ | ---------------------------------- |
| Complex             | two C floats (I,Q) | sizeof(float)*2, generally 8 bytes |
| Float               | float              | sizeof(float), generaly 4 bytes    |
| Int                 | int                | sizeof(int), generally 4 bytes     |
| Short               | short              | sizeof(short), generally 2 bytes   |
| Byte                | unsigned char      | sizeof(unsigned char), 1 byte      |

Since the actual size of some objects may depend on the host platform,
it is recommended to use the available language definitions to get
correct sizes. Most languages are also providing routines to
read/write native machine C types. See examples provided in this
package for some languages.

A typical source block command will produce data "forever" on its
standard output, until a SIGTERM is sent by the pipe.source block to
ask for normal termination. Also, in case of an exception, the pipe
will be closed and a SIGPIPE will be caught.

A typical sink block command will consume data on its standard input,
until end-of-file (EOF) is read, for a proper termination.

A typical filter block command will comsume data "forever" on its
standard input, process it, and produce data on its standard output,
until end-of-file (EOF) is read, for normal termination. Also in case
of exception, SIGPIPE may be caught.

In pipe blocks, commands are executed in a /bin/sh shell, so every
standard shell features are available in commands provided to blocks
(variables, loops, pipes, redirection, etc...).

See examples for a "square" block implemented in C, Java, MatLab/GNU
Octave, Perl and Python.

Suggestions of use:

* Compression (gzip, lzma, ...)
* Encryption (gpg, openssl, ...)
* Encoding (ffmpeg, mencoder, gsm-tools, ...)
* Debugging (od, hexdump, ...)
* Interface to devices (aplay, arecord, pacat, parec, ...)
* Use your own tools...

Known limitations and problems:

* Small performance loss, due to pipe communications.
* Small addition of latency, due to pipe buffers.  (On Linux, pipe
  buffer capacity can be changed.  See fcntl(2) F_SETPIPE_SZ).
* Not compatible with stream tags
* Limited to only one input and one output maximum per block
  (but you may use an interleaver or multiple blocks).


## Building and installing gr-pipe ##

### Installing with GNU Radio PyBOMBS ###

First, install PyBOMBS on your system, following the instructions at:
https://github.com/gnuradio/pybombs

For example:

    pip3 install --user --upgrade git+https://github.com/gnuradio/pybombs.git
    pybombs auto-config
    pybombs recipes add-defaults
    pybombs prefix init ~/my-gnuradio

Then, install gr-pipe using the PyBOMBS recipe:

    pybombs install gr-pipe

Finally, to use the gr-pipe blocks in gnuradio-companion:

    source ~/my-gnuradio/setup_env.sh
    gnuradio-companion

or, using the PyBOMBS command:

    pybombs run gnuradio-companion


### Installing manually ###

This procedure assumes you have development tools and GNU Radio
already already installed.

    git clone git://github.com/jolivain/gr-pipe.git
    mkdir gr-pipe/build
    cd gr-pipe/build
    cmake ..
    make
    sudo make install


Feedback and comments are welcome !

Julien Olivain <juju@cotds.org>
