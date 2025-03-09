#include <adf.h>
#include "adf/window/types.h"
#include "aie_api/aie.hpp"
#include "aie_api/aie_adf.hpp"
#include "../include.h"

#define NF 4  // Número de coeficientes del filtro
#define coeffs ((int32_t[]){1024, 512, 256, 128, 64})

using namespace adf;

// los buffers de entrada y salida se pasan por referencia para evitar tener que crear una copia local del buffer
void fir_filter(input_window_int32* in, output_window_int32* out) {

    int32_t retardos[NF] = {0};

    for (int i = 0; i < NUM_SAM; i++) {

        for (int j = NF-1; j > 0; j--){
            retardos[j] = retardos[j - 1];
        }

        retardos[0] = window_readincr(in);
        int32 y = 0;

        for (int j = 0; j < NF; j++) {
            y += coeffs[j] * retardos[j];
        }

        printf("---Iteracion nº %d \n", i+1);
        printf("x = %d \n", retardos[0]);
        printf("y = %d \n", y);

        window_writeincr(out, y);
    }
}





/*

void fir_hls(hls::stream<int32_t> &in_stream, 
               hls::stream<int32_t> &out_stream) {


    int32_t shift_reg[NF] = {0};

    for (unsigned i = 0; i < NUM_SAM; i++) {

        // desplzamiento de los delays
        for (int j = NF - 1; j > 0; j--) {
            shift_reg[j] = shift_reg[j - 1];
        }
        shift_reg[0] = in_stream.read();

        // Filtrado 
        int32_t acc = 0;
        for (unsigned j = 0; j < NF; j++) {
            acc += shift_reg[j] * Coeff[j];
        }

        out_stream.write(acc);
    }
}

*/


