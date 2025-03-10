
#pragma once

#include <adf.h>

#define MARGIN		0      	// se utiliza para inicializar el filtro y calcular el valor correcto de la primera muestra. 
                            // debe ser al menos igual al numero de coeficientes del filtro (orden -1)

#define NUM_SAM		64		// Numero de muestras a filtrar


#define INPUT_FILE "data/delta.txt"    // path al fichero de entrada
#define OUTPUT_FILE "data/out1.txt"    


