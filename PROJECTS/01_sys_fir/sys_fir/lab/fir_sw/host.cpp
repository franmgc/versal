#include <fstream>
#include <cstring> // para poder usar memcpy() y memset()
#include <hls_stream.h>

#include "experimental/xrt_kernel.h"
#include "experimental/xrt_graph.h"
#include "data.h" // contiene la señal de entrada y la salida esperada

#define SAMPLES 256

int main(int argc, char* argv[])
{
	//////////////////////////////////////////
	// Open xclbin
	//////////////////////////////////////////	

    // XCLBIN: equivalente a un bitstream, encapsula toda la configuración del HW, permitiendo que el SW lo cargue y lo ejecute dinámicamente.

	char* xclbinFile=argv[1];
	auto device = xrt::device(0);
    	if(device == nullptr)
		throw std::runtime_error("No valid device handle found. Make sure using right xclOpen index.");
    	auto xclbin_uuid = device.load_xclbin(xclbinFile); //Se abre el dispositivo (xrt::device). Se carga el xclbinFile en el dispositivo. Se obtiene un identificador UUID que se usa para instanciar kernels y grafos.

    int sizeIn = SAMPLES/2;
	int sizeOut = SAMPLES;

	//////////////////////////////////////////
	// Reserva de la memoria de entrada
	// MM2S module transfers input data from PL to the AI Engine
	//////////////////////////////////////////
		
	auto in_bohdl = xrt::bo(device, sizeIn * sizeof(int16_t) * 2, 0, 0); // bo = buffer object, se usa para reservar memoria en bytes
	auto in_bomapped = in_bohdl.map<uint32_t*>(); // Permite acceder a los datos como un puntero normal en la PS.
	memcpy(in_bomapped, entrada, sizeIn * sizeof(int16_t) * 2); // carga la variable cint16Input en la memoria
	printf("Input memory virtual addr 0x%px\n", in_bomapped);

    //bo.sync(XCL_BO_SYNC_BO_TO_DEVICE): Copia los datos PS → PL
    //bo.sync(XCL_BO_SYNC_BO_FROM_DEVICE): Copia los datos PL → PS
	in_bohdl.sync(XCL_BO_SYNC_BO_TO_DEVICE);

	//////////////////////////////////////////
	// Reserva de la memoria de salida
	// S2MM module receives the output data from AI Engine 
	//////////////////////////////////////////
	
	auto out_bohdl = xrt::bo(device, sizeOut * sizeof(int), 0, 0);
	auto out_bomapped = out_bohdl.map<uint32_t*>();
	memset(out_bomapped, 0xABCDEF00, sizeOut * sizeof(int)); //memset() llena toda la memoria con el valor 0xABCDEF00
	printf("Output memory virtual addr 0x%px\n", out_bomapped); // muestra la direccion de la memoria donde se creó el buffer

	////////////////////////////////////////////////////////
	// mm2s ip - Creating kernel handle using xrt::kernel API
	///////////////////////////////////////////////////////	
	
	auto mm2s_khdl = xrt::kernel(device, xclbin_uuid, "mm2s");
	auto mm2s_rhdl = mm2s_khdl(in_bohdl, nullptr, sizeIn);
	printf("run mm2s\n");

	////////////////////////////////////////////////////////
	// FIR HLS
	///////////////////////////////////////////////////////	
    hls::stream<int> in_stream;
    hls::stream<int> out_stream;
	
	auto firhls_khdl = xrt::kernel(device, xclbin_uuid, "fir_hls");
    auto firhls_rhdl = firhls_khdl(in_stream, out_stream);
	printf("run fir_hls\n");

	////////////////////////////////////////////////////////
	// s2mm ip - Creating kernel handle using xrt::kernel API
	///////////////////////////////////////////////////////		
	
	auto s2mm_khdl = xrt::kernel(device, xclbin_uuid, "s2mm");
	auto s2mm_rhdl = s2mm_khdl(out_bohdl, nullptr, sizeOut);
	printf("run s2mm\n");

	//////////////////////////////////////////
	// graph execution for AIE
	//////////////////////////////////////////	
	
	//Obtains the graph handle from the XCLBIN that is loaded into the device
	auto cghdl = xrt::graph(device,xclbin_uuid,"G");
	
	printf("graph run\n");
	//Run th graph for 1 iteration
	cghdl.run(1);
	
	//Graph end
	cghdl.end();
	printf("graph end\n");	
	
	
	//////////////////////////////////////////
	// wait for mm2s done
	//////////////////////////////////////////	
	
	mm2s_rhdl.wait(); // bloquea la CPU hasta que mm2s haya finalizado la transferencia de datos.

	//////////////////////////////////////////
	// wait for fir_hls done
	//////////////////////////////////////////	
	
	firhls_rhdl.wait(); 

	//////////////////////////////////////////
	// wait for s2mm done
	//////////////////////////////////////////	
	
	s2mm_rhdl.wait();

	out_bohdl.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
	
	//////////////////////////////////////////
	// Comparing the execution data to the golden data
	//////////////////////////////////////////	
	


		for (int i = 0; i < sizeOut; i++)
		{

			printf("||||||||||| found @ index = %d, value = %d \n", i, out_bomapped[i]);

		}
        return 0;

    /*
	int errorCount = 0;
	{
		for (int i = 0; i < sizeOut; i++)
		{
				if ((signed)out_bomapped[i] != golden[i])
				{
					printf("Error found @ %d, %d != %d\n", i, out_bomapped[i], golden[i]);
					errorCount++;
				}
		}

		if (errorCount)
			printf("Test failed with %d errors\n", errorCount);
		else
			printf("TEST PASSED\n");
	}
	
    
	std::cout << "Releasing remaining XRT objects...\n";
	
	return errorCount;
        */

}
