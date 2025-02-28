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
 * Kernel weighted_sum
 *
 * Compute the weighted sum of the last 8 values.
 */

#include <adf.h>
#include "../include.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "aie_api/utils.hpp"

using namespace adf;

alignas(aie::vector_decl_align) int32 weights[8] =	{ 1, 2, 3, 4, 5, 6, 7, 8};

void vectorized_weighted_sum_with_margin(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & restrict in, output_buffer<int32,extents<NUM_SAM>> & restrict out)
{
	auto inIter=aie::begin_vector<8>(in);
	auto outIter=aie::begin_vector<8>(out);

	aie::vector<int32,8> coeffs = aie::load_v<8>(weights); // Load the coeffs vector with weights

	aie::vector<int32,16> data;
	aie::accum<acc80,4> acc;
	aie::vector<int32,8> dataout;

	data.insert(0,*inIter++); 	// Reading samples for - 0

	for(unsigned i=0; i<NUM_SAM/16; i++)
		chess_prepare_for_pipelining
		chess_loop_range(4,32)
	{
		data.insert(1, *inIter++);	// Reading samples for - 1

		// mul preforms multiplication accumulations with no initial value for the accumulator
		acc = aie::sliding_mul<4,8>(coeffs, 0, data, 1);

		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(0,acc.to_vector<int32>());

		acc = aie::sliding_mul<4,8>(coeffs, 0, data, 5);

		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(1,acc.to_vector<int32>());
		*outIter++=dataout;

		data.insert(0, *inIter++);	// Reading samples for - 0

		acc = aie::sliding_mul<4,8>(coeffs, 0, data, 9);

		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(0,acc.to_vector<int32>());

		acc = aie::sliding_mul<4,8>(coeffs, 0, data, 13);

		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(1,acc.to_vector<int32>());
		*outIter++=dataout;
	}
}