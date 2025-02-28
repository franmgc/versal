//<copyright-disclaimer-start>
//  **************************************************************************************************************
//  * © 2023 Advanced Micro Devices, Inc. All rights reserved.                                                   *
//  * DISCLAIMER                                                                                                 *
//  * The information contained herein is for informational purposes only, and is subject to change              *
//  * without notice. While every precaution has been taken in the preparation of this document, it              *
//  * may contain technical inaccuracies, omissions and typographical errors, and AMD is under no                *
//  * obligation to update or otherwise correct this information.  Advanced Micro Devices, Inc. makes            *
//  * no representations or warranties with respect to the accuracy or completeness of the contents of           *
//  * this document, and assumes no liability of any kind, including the implied warranties of noninfringement,  *
//  * merchantability or fitness for particular purposes, with respect to the operation or use of AMD            *
//  * hardware, software or other products described herein.  No license, including implied or                   *
//  * arising by estoppel, to any intellectual property rights is granted by this document.  Terms and           *
//  * limitations applicable to the purchase or use of AMD’s products are as set forth in a signed agreement     *
//  * between the parties or in AMD's Standard Terms and Conditions of Sale. GD-18                               *
//  *                                                                                                            *
//  **************************************************************************************************************
//<copyright-disclaimer-end>


#include "graph.h"

using namespace adf;

clipped clipgraph; //A graph object 'clipgraph' is declared

//This main() function runs only for AIESIM and X86Sim targets. 
//Emulation uses a different host code
#if defined(__AIESIM__) || defined(__X86SIM__)
int main(int argc, char ** argv) {
	clipgraph.init(); //Loads the graph to the AI Engine Array
    	clipgraph.run(4); //Starts the graph execution by enabling the processors.
    	clipgraph.end(); //Wait for 4 iterations to finish
    	return 0;
	}
#endif
