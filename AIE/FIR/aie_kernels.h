


#pragma once

#include <adf.h>
#include "include.h"

using namespace adf;

void fir_filter(input_buffer<int32,extents<NUM_SAM>,margin<MARGIN>> & in, output_buffer<int32,extents<NUM_SAM>> & out);
