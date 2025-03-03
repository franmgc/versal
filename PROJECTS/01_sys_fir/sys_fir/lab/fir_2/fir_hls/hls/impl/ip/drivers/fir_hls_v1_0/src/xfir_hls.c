// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xfir_hls.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XFir_hls_CfgInitialize(XFir_hls *InstancePtr, XFir_hls_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XFir_hls_Start(XFir_hls *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL) & 0x80;
    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XFir_hls_IsDone(XFir_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XFir_hls_IsIdle(XFir_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XFir_hls_IsReady(XFir_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XFir_hls_Continue(XFir_hls *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL) & 0x80;
    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XFir_hls_EnableAutoRestart(XFir_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XFir_hls_DisableAutoRestart(XFir_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_AP_CTRL, 0);
}

void XFir_hls_InterruptGlobalEnable(XFir_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_GIE, 1);
}

void XFir_hls_InterruptGlobalDisable(XFir_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_GIE, 0);
}

void XFir_hls_InterruptEnable(XFir_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_IER);
    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_IER, Register | Mask);
}

void XFir_hls_InterruptDisable(XFir_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_IER);
    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_IER, Register & (~Mask));
}

void XFir_hls_InterruptClear(XFir_hls *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFir_hls_WriteReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_ISR, Mask);
}

u32 XFir_hls_InterruptGetEnabled(XFir_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_IER);
}

u32 XFir_hls_InterruptGetStatus(XFir_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFir_hls_ReadReg(InstancePtr->Control_BaseAddress, XFIR_HLS_CONTROL_ADDR_ISR);
}

