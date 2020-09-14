title: The Pipe Module
brief: Collection of blocks for using any program as a source, sink or filter using Unix pipes.
tags: # Tags are arbitrary, but look at CGRAN what other authors are using
  - sdr
  - interface
author:
  - Julien Olivain <juju@cotds.org>
copyright_owner:
  - Julien Olivain
license: GPLv2
gr_supported_version: v3.8
repo: https://github.com/jolivain/gr-pipe
---
gr-pipe is a set GNU Radio block for using any program as a source,
sink or filter by using standard Unix I/O pipes.

The main goals of these blocks are:
- Fast development of new experimental blocks (no need to dig into C++
  / GNU Radio internals / SWIG / Python).
- Ability to use any programming language able to deal with standard
  input and output (code a block in your preferred language: C, Java,
  MatLab, Perl, Ruby...).
- Simple interface: sequence of raw samples
