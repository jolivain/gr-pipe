/* -*- c++ -*- */

#define PIPE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "pipe_swig_doc.i"

%{
#include "pipe/filter.h"
#include "pipe/source.h"
#include "pipe/sink.h"
%}

%include "pipe/filter.h"
GR_SWIG_BLOCK_MAGIC2(pipe, filter);
%include "pipe/source.h"
GR_SWIG_BLOCK_MAGIC2(pipe, source);
%include "pipe/sink.h"
GR_SWIG_BLOCK_MAGIC2(pipe, sink);
