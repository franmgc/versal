

#include "include.h"	
#include "graph.h"
#include <adf.h>

using namespace adf;

FirstGraph G; //constructor del graph

#if defined(__AIESIM__) || defined(__X86SIM__)

int main()
{	
	
    G.init();
    G.run(1); // NITER=1 --> solo hace una iteración
    G.end();

    return 0;
}

#endif
