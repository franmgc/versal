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


#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <adf.h>
#include "include.h"
#include "kernels.h"

using namespace adf;

class clipped : public adf::graph {  

  private:
    kernel interpolator;
    kernel classify;
    kernel clip;
   
  public:
      
    //Declaring PLIO objects
    adf::input_plio in;
    adf::output_plio out;

    clipped() {
      //kernel instantiation
      interpolator = adf::kernel::create(fir_27t_sym_hb_2i);
      clip         = adf::kernel::create(polar_clip);
      classify     = adf::kernel::create(classifier);
      
      adf::source(interpolator) = "kernels/interpolators/hb27_2i.cc";
      adf::source(clip)         = "kernels/polar_clip.cpp";
      adf::source(classify)    = "kernels/classifiers/classify.cc";
      
      //Input PLIO object that specifies the file containing input data
      in = adf::input_plio::create("DataIn1", adf::plio_32_bits,"data/input.txt");
      
      //Output PLIO object that specifies the file containing output data
      out = adf::output_plio::create("DataOut1",adf::plio_32_bits, "data/output.txt");

      //connection between buffer port 'in' and 'input port of the kernel
      connect(in.out[0], interpolator.in[0]);

      connect(interpolator.out[0], clip.in[0]);
      
      //stream connection between kernels
      connect(clip.out[0], classify.in[0]);
      
      //connection between output buffer port of the kernel and port 'out'
      connect(classify.out[0], out.in[0]);

      //Dimensions - Specifying the size of the buffers
      dimensions(interpolator.in[0]) = {INTERPOLATOR27_INPUT_SAMPLES};
      dimensions(interpolator.out[0]) = {POLAR_CLIP_INPUT_SAMPLES};
      dimensions(classify.out[0]) = {CLASSIFIER_OUTPUT_SAMPLES};

      std::vector<std::string> myheaders;
      myheaders.push_back("include.h");

      adf::headers(interpolator) = myheaders;
      adf::headers(classify) = myheaders;
      
      //Specifying core usage fraction for a kernel
      runtime<ratio>(interpolator) = 0.8;
      runtime<ratio>(clip) = 0.8;
      runtime<ratio>(classify) = 0.8;
    };
};

#endif /**********__GRAPH_H__**********/
