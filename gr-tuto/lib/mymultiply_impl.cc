/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "mymultiply_impl.h"

namespace gr {
  namespace tuto {

    mymultiply::sptr
    mymultiply::make()
    {
      return gnuradio::get_initial_sptr
        (new mymultiply_impl());
    }

    /*
     * The private constructor
     */
    mymultiply_impl::mymultiply_impl()
      : gr::block("mymultiply",
              gr::io_signature::make(2, 2, sizeof (float)), // Number and type of inputs
              gr::io_signature::make(1, 1, sizeof (float))) // Number and type of outputs
    {}

    /*
     * Our virtual destructor.
     */
    mymultiply_impl::~mymultiply_impl()
    {
    }

    void
    mymultiply_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    mymultiply_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in1 = (const float *) input_items[0];
const float *in2 = (const float *) input_items[1];
float *out = (float *) output_items[0];
// Do <+signal processing+>
for(int i = 0; i < noutput_items; i++)
{
  out[i] = in1[i]*in2[i];
}
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace tuto */
} /* namespace gr */

