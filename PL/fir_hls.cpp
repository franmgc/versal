#include "fir_hls.h"
#include <cstdint>
#include <fstream>
#include <hls_stream.h>

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
