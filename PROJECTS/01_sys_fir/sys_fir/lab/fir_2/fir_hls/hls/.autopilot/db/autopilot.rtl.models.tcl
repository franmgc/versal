set SynModuleInfo {
  {SRCNAME fir_hls_Pipeline_1 MODELNAME fir_hls_Pipeline_1 RTLNAME fir_hls_fir_hls_Pipeline_1
    SUBMODULES {
      {MODELNAME fir_hls_flow_control_loop_pipe_sequential_init RTLNAME fir_hls_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME fir_hls_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME fir_hls_Pipeline_VITIS_LOOP_12_1 MODELNAME fir_hls_Pipeline_VITIS_LOOP_12_1 RTLNAME fir_hls_fir_hls_Pipeline_VITIS_LOOP_12_1}
  {SRCNAME fir_hls MODELNAME fir_hls RTLNAME fir_hls IS_TOP 1
    SUBMODULES {
      {MODELNAME fir_hls_control_s_axi RTLNAME fir_hls_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME fir_hls_regslice_both RTLNAME fir_hls_regslice_both BINDTYPE interface TYPE interface_regslice INSTNAME fir_hls_regslice_both_U}
    }
  }
}
