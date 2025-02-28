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


#include <adf.h>
#include <aie_api/aie.hpp>
#include "../../include.h"

using namespace adf;

void classifier(input_stream_cint16 * input, 
                output_buffer<int32> & __restrict output
){
    
    const unsigned output_samples =  CLASSIFIER_OUTPUT_SAMPLES ;
    auto OutIter = aie::begin(output);
    for (unsigned l=0;l<output_samples;l++) {
      cint16 sample = readincr(input);

    if (sample.real >= 0) {
      if (sample.imag > 0)

                *OutIter++ = 0;
        else
          	*OutIter++ = 1;
      }
      else {
        
      if (sample.imag > 0)
          
          *OutIter++ = 2;
        else
          
	  *OutIter++ = 3;
      }
    }
}

