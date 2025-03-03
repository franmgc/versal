#include <adf.h>
#include "adf/window/types.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "../include.h"

using namespace adf;

// los buffers de entrada y salida se pasan por referencia para evitar tener que crear una copia local del buffer
void fir_filter(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & in, output_buffer<int32,extents<NUM_SAM>> & out)
{
	auto x=aie::begin_random_circular(in);  //iterador circular sobre el buffer de entrada (in)
	auto y=aie::begin_random_circular(out);



	for (unsigned i = 0; i < NUM_SAM; i++)
	{
		int32 aux;
		int32 acc = 0; 

		
		for (unsigned j = 0; j < NF; j++)
		{

			aux=*x++;
			acc = acc + (Coeff[j] * aux); //acc += x[i - j] * Coeff[j];
		}

		*y++=acc;
	}
}


