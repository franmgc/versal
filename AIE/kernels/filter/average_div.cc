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

/* 
 * Kernel average_div
 *
 * Compute the weighted average by dividing each value by 36.
 */

#include <adf.h>
#include "../include.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "aie_api/utils.hpp"

using namespace adf;

void average_div(input_buffer<int32,extents<NUM_SAM>> & in, output_buffer<int32,extents<NUM_SAM>> & out)
{
	auto inIter=aie::begin_random_circular(in);
	auto outIter=aie::begin_random_circular(out);

	for (unsigned i = 1; i <= NUM_SAM; i++)
  {
    int32 c1;
    c1 = *inIter++;	
    *outIter++=c1/36;	
  }
}


#define SHIFT 30
int32 s = (1<<SHIFT)/36;
alignas(aie::vector_decl_align) int32 scale[8] = { s, s, s, s, s, s, s, s};

void vectorized_average_div(input_buffer<int32,extents<NUM_SAM>> & restrict in, output_buffer<int32, extents<NUM_SAM>> & restrict out)
{

	auto inIter=aie::begin_vector<8>(in);
	auto outIter=aie::begin_vector<8>(out);

	aie::vector<int32,8> sc ;	
	sc = *(v8int32*) scale;
	aie::vector<int32,8> data;	
	aie::vector<int32,8> dataout;	
	aie::accum<acc80,8> acc;	

	for (unsigned i = 0; i < NUM_SAM/8; i++)
		chess_prepare_for_pipelining
		chess_loop_range(4,32)
	{
		data=*inIter++; 
		acc = mul(data,sc);
		*outIter++=srs(acc,SHIFT); 
	}
}

