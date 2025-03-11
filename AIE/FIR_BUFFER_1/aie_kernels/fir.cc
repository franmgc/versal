#include <adf.h>
#include <cstdint>
#include "adf/window/types.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "aie_api/utils.hpp"
#include "../include.h"

#define NF 8  // Número de coeficientes del filtro

alignas(aie::vector_decl_align) int32 b[8] ={1024, 512, 256, 128, 64, 32, 16, 8};

using namespace adf;

// los buffers de entrada y salida se pasan por referencia para evitar tener que crear una copia local del buffer
void fir_filter(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & in, output_buffer<int32,extents<NUM_SAM>> & out) {
	auto inIter=aie::begin_vector<8>(in);
	auto outIter=aie::begin_vector<8>(out);

	aie::vector<int32,8> coeffs = aie::load_v<8>(b); // Load the coeffs vector with weights

	aie::vector<int32,16> data;
	aie::accum<acc80,8> acc;
	aie::vector<int32,8> dataout;

	data.insert(0,*inIter++); 	// Reading samples for - 0

	for(unsigned i=0; i<NUM_SAM/16; i++) {

		data.insert(0, *inIter++);	// Reading samples for - 0
		acc = aie::sliding_mul<8,8>(coeffs, 0, data, 9);
		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(0,acc.to_vector<int32>());
		*outIter++=dataout;


		data.insert(1, *inIter++);	// Reading samples for - 1
		// mul preforms multiplication accumulations with no initial value for the accumulator
        // sliding_mul<4U, 8U, 1, 1, 1, accauto, aie::vector<int, 8>, aie::vector<int, 8>>
		acc = aie::sliding_mul<8,8>(coeffs, 0, data, 1);
		// Convert acc to vector & Write it to out window and increment the pointer
		dataout.insert(0,acc.to_vector<int32>());
		*outIter++=dataout;

	}
}
