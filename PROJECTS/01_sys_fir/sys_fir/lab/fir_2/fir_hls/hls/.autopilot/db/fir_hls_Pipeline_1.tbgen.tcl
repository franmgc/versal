set moduleName fir_hls_Pipeline_1
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {fir_hls_Pipeline_1}
set C_modelType { void 0 }
set C_modelArgList {
	{ shift_reg_6_out int 29 regular {pointer 1}  }
	{ shift_reg_5_out int 29 regular {pointer 1}  }
	{ shift_reg_4_out int 29 regular {pointer 1}  }
	{ shift_reg_3_out int 29 regular {pointer 1}  }
	{ shift_reg_2_out int 29 regular {pointer 1}  }
	{ shift_reg_1_out int 29 regular {pointer 1}  }
	{ shift_reg_out int 29 regular {pointer 1}  }
}
set hasAXIMCache 0
set AXIMCacheInstList { }
set C_modelArgMapList {[ 
	{ "Name" : "shift_reg_6_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_5_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_4_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_3_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_2_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_1_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} , 
 	{ "Name" : "shift_reg_out", "interface" : "wire", "bitwidth" : 29, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ shift_reg_6_out sc_out sc_lv 29 signal 0 } 
	{ shift_reg_6_out_ap_vld sc_out sc_logic 1 outvld 0 } 
	{ shift_reg_5_out sc_out sc_lv 29 signal 1 } 
	{ shift_reg_5_out_ap_vld sc_out sc_logic 1 outvld 1 } 
	{ shift_reg_4_out sc_out sc_lv 29 signal 2 } 
	{ shift_reg_4_out_ap_vld sc_out sc_logic 1 outvld 2 } 
	{ shift_reg_3_out sc_out sc_lv 29 signal 3 } 
	{ shift_reg_3_out_ap_vld sc_out sc_logic 1 outvld 3 } 
	{ shift_reg_2_out sc_out sc_lv 29 signal 4 } 
	{ shift_reg_2_out_ap_vld sc_out sc_logic 1 outvld 4 } 
	{ shift_reg_1_out sc_out sc_lv 29 signal 5 } 
	{ shift_reg_1_out_ap_vld sc_out sc_logic 1 outvld 5 } 
	{ shift_reg_out sc_out sc_lv 29 signal 6 } 
	{ shift_reg_out_ap_vld sc_out sc_logic 1 outvld 6 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "shift_reg_6_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_6_out", "role": "default" }} , 
 	{ "name": "shift_reg_6_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_6_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_5_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_5_out", "role": "default" }} , 
 	{ "name": "shift_reg_5_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_5_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_4_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_4_out", "role": "default" }} , 
 	{ "name": "shift_reg_4_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_4_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_3_out", "role": "default" }} , 
 	{ "name": "shift_reg_3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_3_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_2_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_2_out", "role": "default" }} , 
 	{ "name": "shift_reg_2_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_2_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_1_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_1_out", "role": "default" }} , 
 	{ "name": "shift_reg_1_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_1_out", "role": "ap_vld" }} , 
 	{ "name": "shift_reg_out", "direction": "out", "datatype": "sc_lv", "bitwidth":29, "type": "signal", "bundle":{"name": "shift_reg_out", "role": "default" }} , 
 	{ "name": "shift_reg_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "shift_reg_out", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "fir_hls_Pipeline_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "10", "EstimateLatencyMax" : "10",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "shift_reg_6_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_5_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_4_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_3_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_2_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_1_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "shift_reg_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "Loop 1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_state1", "FirstStateIter" : "", "FirstStateBlock" : "ap_ST_fsm_state1_blk", "LastState" : "ap_ST_fsm_state1", "LastStateIter" : "", "LastStateBlock" : "ap_ST_fsm_state1_blk", "QuitState" : "ap_ST_fsm_state1", "QuitStateIter" : "", "QuitStateBlock" : "ap_ST_fsm_state1_blk", "OneDepthLoop" : "1", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fir_hls_Pipeline_1 {
		shift_reg_6_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_5_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_4_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_3_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_2_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_1_out {Type O LastRead -1 FirstWrite 0}
		shift_reg_out {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "10", "Max" : "10"}
	, {"Name" : "Interval", "Min" : "10", "Max" : "10"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	shift_reg_6_out { ap_vld {  { shift_reg_6_out out_data 1 29 }  { shift_reg_6_out_ap_vld out_vld 1 1 } } }
	shift_reg_5_out { ap_vld {  { shift_reg_5_out out_data 1 29 }  { shift_reg_5_out_ap_vld out_vld 1 1 } } }
	shift_reg_4_out { ap_vld {  { shift_reg_4_out out_data 1 29 }  { shift_reg_4_out_ap_vld out_vld 1 1 } } }
	shift_reg_3_out { ap_vld {  { shift_reg_3_out out_data 1 29 }  { shift_reg_3_out_ap_vld out_vld 1 1 } } }
	shift_reg_2_out { ap_vld {  { shift_reg_2_out out_data 1 29 }  { shift_reg_2_out_ap_vld out_vld 1 1 } } }
	shift_reg_1_out { ap_vld {  { shift_reg_1_out out_data 1 29 }  { shift_reg_1_out_ap_vld out_vld 1 1 } } }
	shift_reg_out { ap_vld {  { shift_reg_out out_data 1 29 }  { shift_reg_out_ap_vld out_vld 1 1 } } }
}
