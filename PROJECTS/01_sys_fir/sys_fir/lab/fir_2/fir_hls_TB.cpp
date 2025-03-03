#include <hls_stream.h>
#include <iostream>
#include <vector>
#define NUM_SAM 64

void fir_hls(hls::stream<int> &in_stream, hls::stream<int> &out_stream);

int main() {
    // filtro hecho con streams
    hls::stream<int> in_stream;
    hls::stream<int> out_stream;

    std::vector<int> input_data(NUM_SAM);
    std::vector<int> output_data(NUM_SAM);

    // Delta ---> Respuesta al impulso
    input_data[0] = 1;
    in_stream.write(input_data[0]);

    for (int i = 1; i < NUM_SAM; i++) {
        input_data[i] = 0;
        in_stream.write(input_data[i]);
    }

    fir_hls(in_stream, out_stream);


    while (out_stream.size() < NUM_SAM); // esperamos a que se llene el bufer de salida antes de leerlo

    for (int i = 0; i < NUM_SAM; i++) {
        output_data[i] = out_stream.read();
        std::cout << "Output[" << i << "] = " << output_data[i] << std::endl;
    }


    return 0;
}