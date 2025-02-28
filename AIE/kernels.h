//<copyright-disclaimer-start>
//  **************************************************************************************************************
//  * © 2023 Advanced Micro Devices, Inc. All rights reserved.                                                   *
//  * DISCLAIMER                                                                                                 *
//  * The information contained herein is for informational purposes only, and is subject to change              *
//  * without notice. While every precaution has been taken in the preparation of this document, it              *
//  * may contain technical inaccuracies, omissions and typographical errors, and AMD is under no                *
//  * obligation to update or otherwise correct this information.  Advanced Micro Devices, Inc. makes            *
//  * no representations or warranties with respect to the accuracy or completeness of the contents of           *
//  * this document, and assumes no liability of any kind, including the implied warranties of noninfringement,  *
//  * merchantability or fitness for particular purposes, with respect to the operation or use of AMD            *
//  * hardware, software or other products described herein.  No license, including implied or                   *
//  * arising by estoppel, to any intellectual property rights is granted by this document.  Terms and           *
//  * limitations applicable to the purchase or use of AMD’s products are as set forth in a signed agreement     *
//  * between the parties or in AMD's Standard Terms and Conditions of Sale. GD-18                               *
//  *                                                                                                            *
//  **************************************************************************************************************
//<copyright-disclaimer-end>


#ifndef __KERNELS_H__
#define __KERNELS_H__

#include <adf.h>
#include <aie_api/aie.hpp>
using namespace adf;

  void classifier(input_stream_cint16 * input, 
                  output_buffer<int32> & __restrict output);

  void fir_27t_sym_hb_2i(       
	input_buffer<cint16,adf::extents<adf::inherited_extent>,adf::margin<INTERPOLATOR27_COEFFICIENTS>>  & __restrict cb_input,
	output_buffer<cint16> & __restrict cb_output);

  void polar_clip(input_stream_cint16* in, 
                  output_stream_cint16 *out);

#endif /**********__KERNELS_H__**********/
