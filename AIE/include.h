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


#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#define INTERPOLATOR27_INPUT_SAMPLES 128
//NOTE: THIS AMOUNT MUST AGREE WITH THE INPUT_SAMPLES IN HOST.CPP

#define INTERPOLATOR27_INPUT_MARGIN (16*4)
#define INTERPOLATOR27_COEFFICIENTS 16
#define INTERPOLATOR27_OUTPUT_SAMPLES (INTERPOLATOR27_INPUT_SAMPLES * 2)
#define INTERPOLATOR27_INPUT_BLOCK_SIZE (INTERPOLATOR27_INPUT_SAMPLES * 4)

#define POLAR_CLIP_INPUT_SAMPLES (INTERPOLATOR27_OUTPUT_SAMPLES)
#define POLAR_CLIP_INPUT_BLOCK_SIZE (POLAR_CLIP_INPUT_SAMPLES * 4)
#define POLAR_CLIP_OUTPUT_SAMPLES (POLAR_CLIP_INPUT_SAMPLES)

#define CLASSIFIER_OUTPUT_SAMPLES (POLAR_CLIP_OUTPUT_SAMPLES)
#define CLASSIFIER_OUTPUT_BLOCK_SIZE (CLASSIFIER_OUTPUT_SAMPLES * 4)

#endif /**********__INCLUDE_H__**********/
