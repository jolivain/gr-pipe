/* -*- c++ -*- */

#define PIPE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "pipe_swig_doc.i"


%{
#include "pipe_filter.h"
%}

%include "pipe_filter.i"
