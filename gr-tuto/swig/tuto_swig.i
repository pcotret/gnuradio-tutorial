/* -*- c++ -*- */

#define TUTO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tuto_swig_doc.i"

%{
#include "tuto/mysquare.h"
#include "tuto/mymultiply.h"
%}


%include "tuto/mysquare.h"
GR_SWIG_BLOCK_MAGIC2(tuto, mysquare);
%include "tuto/mymultiply.h"
GR_SWIG_BLOCK_MAGIC2(tuto, mymultiply);
