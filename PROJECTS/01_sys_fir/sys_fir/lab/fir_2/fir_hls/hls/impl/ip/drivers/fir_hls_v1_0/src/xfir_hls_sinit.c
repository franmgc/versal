// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xfir_hls.h"

extern XFir_hls_Config XFir_hls_ConfigTable[];

#ifdef SDT
XFir_hls_Config *XFir_hls_LookupConfig(UINTPTR BaseAddress) {
	XFir_hls_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XFir_hls_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XFir_hls_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XFir_hls_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XFir_hls_Initialize(XFir_hls *InstancePtr, UINTPTR BaseAddress) {
	XFir_hls_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XFir_hls_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XFir_hls_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XFir_hls_Config *XFir_hls_LookupConfig(u16 DeviceId) {
	XFir_hls_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XFIR_HLS_NUM_INSTANCES; Index++) {
		if (XFir_hls_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XFir_hls_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XFir_hls_Initialize(XFir_hls *InstancePtr, u16 DeviceId) {
	XFir_hls_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XFir_hls_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XFir_hls_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

