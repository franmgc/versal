#include <adf.h>
#include <cstdint>
#include "adf/window/types.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "../include.h"

#define NF 5  // Número de coeficientes del filtro
#define Coeff ((int32_t[]){1024, 512, 256, 128, 64, 32, 16, 8})

using namespace adf;

// los buffers de entrada y salida se pasan por referencia para evitar tener que crear una copia local del buffer
void fir_filter(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & in, output_buffer<int32,extents<NUM_SAM>> & out)
{
	auto x=aie::begin_circular(in);  //iterador circular sobre el buffer de entrada (in)
	auto y=aie::begin_circular(out);
    
    int32_t retardos[NF] = {0};



	for (unsigned i = 0; i < NUM_SAM; i++)
	{

        for (int j = NF-1; j > 0; j--){
            retardos[j] = retardos[j - 1];
        }

        retardos[0] = *x;

        printf("---Iteracion nº %d \n", i+1);
        printf("x = %d \n", retardos[0]);
        // printf("y = %d \n", y);
        int32 acc = 0;
		int32 aux;

		for (unsigned j = 0; j < NF; j++)
		{

			acc +=  (Coeff[j] * retardos[j]); //acc += x[i - j] * Coeff[j];
		}

        *y = acc;
        y++;
		//*y++=acc;
        x++;
	}
}


