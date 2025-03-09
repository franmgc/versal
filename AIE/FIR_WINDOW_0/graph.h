#pragma once

#include <adf.h>
#include "aie_kernels.h"
#include "include.h"

using namespace adf;

class FirstGraph : public adf::graph
{
private:
  adf::kernel k;

public:
  adf::input_plio pl_in;
  adf::output_plio pl_out;

  FirstGraph()
  {
	// Creación de los puertos PLIO
    pl_in = input_plio::create("PLIO_In", plio_32_bits, INPUT_FILE);
    pl_out = output_plio::create("PLIO_Out", plio_32_bits, OUTPUT_FILE);



	// crea un kernel "k" basado en la función "fir_filter"
    k = adf::kernel::create(fir_filter);
    // codigo fuente del kernel
    adf::source(k) = "aie_kernels/fir.cc";


    // conexiones entre kernels y puertos IO 
    //adf::connect<> net0 (pl_in.out[0], k.in[0]);
    //adf::connect<> net1 (k.out[0], pl_out.in[0]);

    //adf::connect<stream> net0 (pl_in.out[0], k.in[0]);
    //adf::connect<stream> net1 (k.out[0], pl_out.in[0]);

    adf::connect<window<NUM_SAM*4>> net0 (pl_in.out[0], k.in[0]); //window<bytes> || int32 = 4 bytes --> 64*4 = leer 64 muestras
    adf::connect<window<NUM_SAM*4>> net1 (k.out[0], pl_out.in[0]);


    // opcional, limita el % de uso del kernel "k"
    adf::runtime<ratio>(k) = 0.5;

  }
};



