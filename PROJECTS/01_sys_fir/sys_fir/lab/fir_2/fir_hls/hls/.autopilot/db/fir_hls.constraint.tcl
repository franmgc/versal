set clock_constraint { \
    name clk \
    module fir_hls \
    port ap_clk \
    period 8 \
    uncertainty 0.96 \
}

set all_path {}

set false_path {}

