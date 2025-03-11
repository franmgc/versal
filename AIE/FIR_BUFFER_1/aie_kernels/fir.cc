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


void fir_filter(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & in, output_buffer<int32,extents<NUM_SAM>> & out) {
	auto inIter=aie::begin_vector<NF>(in);
	auto outIter=aie::begin_vector<NF>(out);

	aie::vector<int32,NF> coeffs = aie::load_v<NF>(b); // carga el array de coefs en un vector

	aie::vector<int32,16> data;
	aie::accum<acc80,NF> acc;
	aie::vector<int32,NF> dataout;

	data.insert(0,*inIter++); 	// Lee muestras - 0

	for(unsigned i=0; i<NUM_SAM/16; i++) {

		data.insert(0, *inIter++);	// Lee muestras - 0

        // hace MAC con valor inicial del acumulador = 0
        // aie::accum<acc64, 8> sliding_mul<8U, 8U, 1, 1, 1, accauto, aie::vector<int, 8>, aie::vector<int, 16>>(const aie::vector<int, 8> &coeff, unsigned int coeff_start, const aie::vector<int, 16> &data, unsigned int data_start)
		acc = aie::sliding_mul<NF,NF>(coeffs, 0, data, NF+1);

        // convierte el acumulador a vector        
		dataout.insert(0,acc.to_vector<int32>());
		*outIter++=dataout;

        // ---------

		data.insert(1, *inIter++);	// Lee muestras - 1
		acc = aie::sliding_mul<NF,NF>(coeffs, 0, data, 1);
		dataout.insert(0,acc.to_vector<int32>());
		*outIter++=dataout;

	}
}
