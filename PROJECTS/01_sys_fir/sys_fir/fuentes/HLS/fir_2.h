#include <cstdint>
#define NUM_SAM		64		// Numero de muestras a filtrar

#define NITER       1      	// Numero de iteraciones: G.run(NITER);

#define INPUT_FILE "data/input.txt"    // path al fichero de entrada
#define OUTPUT_FILE "data/out1.txt"    


#define NF 8  // Número de coeficientes del filtro
#define Coeff ((int32_t[]){1024, 512, 256, 128, 64, 32, 16, 8})


