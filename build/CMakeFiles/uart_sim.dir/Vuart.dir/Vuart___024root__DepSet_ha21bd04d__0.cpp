// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart__pch.h"
#include "Vuart___024root.h"

void Vuart___024root___eval_act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vuart___024root___nba_sequent__TOP__0(Vuart___024root* vlSelf);

void Vuart___024root___eval_nba(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vuart___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vuart___024root___nba_sequent__TOP__0(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__uart__DOT__tx_state;
    __Vdly__uart__DOT__tx_state = 0;
    IData/*31:0*/ __Vdly__uart__DOT__tx_clk_count;
    __Vdly__uart__DOT__tx_clk_count = 0;
    CData/*2:0*/ __Vdly__uart__DOT__tx_bit_idx;
    __Vdly__uart__DOT__tx_bit_idx = 0;
    CData/*2:0*/ __Vdly__uart__DOT__rx_state;
    __Vdly__uart__DOT__rx_state = 0;
    CData/*0:0*/ __Vdly__rx_valid;
    __Vdly__rx_valid = 0;
    IData/*31:0*/ __Vdly__uart__DOT__rx_clk_count;
    __Vdly__uart__DOT__rx_clk_count = 0;
    CData/*2:0*/ __Vdly__uart__DOT__rx_bit_idx;
    __Vdly__uart__DOT__rx_bit_idx = 0;
    // Body
    __Vdly__uart__DOT__rx_state = vlSelfRef.uart__DOT__rx_state;
    __Vdly__rx_valid = vlSelfRef.rx_valid;
    __Vdly__uart__DOT__rx_clk_count = vlSelfRef.uart__DOT__rx_clk_count;
    __Vdly__uart__DOT__rx_bit_idx = vlSelfRef.uart__DOT__rx_bit_idx;
    __Vdly__uart__DOT__tx_state = vlSelfRef.uart__DOT__tx_state;
    __Vdly__uart__DOT__tx_clk_count = vlSelfRef.uart__DOT__tx_clk_count;
    __Vdly__uart__DOT__tx_bit_idx = vlSelfRef.uart__DOT__tx_bit_idx;
    if (vlSelfRef.rst) {
        __Vdly__uart__DOT__rx_state = 0U;
        __Vdly__rx_valid = 0U;
        vlSelfRef.rx_data = 0U;
        __Vdly__uart__DOT__rx_clk_count = 0U;
        __Vdly__uart__DOT__rx_bit_idx = 0U;
        __Vdly__uart__DOT__tx_state = 0U;
        vlSelfRef.tx = 1U;
        vlSelfRef.tx_ready = 1U;
        __Vdly__uart__DOT__tx_clk_count = 0U;
        __Vdly__uart__DOT__tx_bit_idx = 0U;
    } else {
        if (vlSelfRef.rx_valid) {
            __Vdly__rx_valid = 0U;
        }
        if ((4U & (IData)(vlSelfRef.uart__DOT__rx_state))) {
            __Vdly__uart__DOT__rx_state = 0U;
        } else if ((2U & (IData)(vlSelfRef.uart__DOT__rx_state))) {
            if ((1U & (IData)(vlSelfRef.uart__DOT__rx_state))) {
                if (VL_GTS_III(32, 7U, vlSelfRef.uart__DOT__rx_clk_count)) {
                    __Vdly__uart__DOT__rx_clk_count 
                        = ((IData)(1U) + vlSelfRef.uart__DOT__rx_clk_count);
                } else {
                    __Vdly__uart__DOT__rx_state = 0U;
                    if (vlSelfRef.rx) {
                        __Vdly__rx_valid = 1U;
                    }
                }
            } else if (VL_GTS_III(32, 7U, vlSelfRef.uart__DOT__rx_clk_count)) {
                __Vdly__uart__DOT__rx_clk_count = ((IData)(1U) 
                                                   + vlSelfRef.uart__DOT__rx_clk_count);
            } else {
                __Vdly__uart__DOT__rx_clk_count = 0U;
                vlSelfRef.rx_data = (((~ ((IData)(1U) 
                                          << (IData)(vlSelfRef.uart__DOT__rx_bit_idx))) 
                                      & (IData)(vlSelfRef.rx_data)) 
                                     | (0xffU & ((IData)(vlSelfRef.rx) 
                                                 << (IData)(vlSelfRef.uart__DOT__rx_bit_idx))));
                if ((7U > (IData)(vlSelfRef.uart__DOT__rx_bit_idx))) {
                    __Vdly__uart__DOT__rx_bit_idx = 
                        (7U & ((IData)(1U) + (IData)(vlSelfRef.uart__DOT__rx_bit_idx)));
                } else {
                    __Vdly__uart__DOT__rx_state = 3U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.uart__DOT__rx_state))) {
            if (VL_GTS_III(32, 3U, vlSelfRef.uart__DOT__rx_clk_count)) {
                __Vdly__uart__DOT__rx_clk_count = ((IData)(1U) 
                                                   + vlSelfRef.uart__DOT__rx_clk_count);
            } else if (vlSelfRef.rx) {
                __Vdly__uart__DOT__rx_state = 0U;
            } else {
                __Vdly__uart__DOT__rx_clk_count = 0U;
                __Vdly__uart__DOT__rx_state = 2U;
                __Vdly__uart__DOT__rx_bit_idx = 0U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.rx)))) {
            __Vdly__uart__DOT__rx_state = 1U;
            __Vdly__uart__DOT__rx_clk_count = 0U;
        }
        if ((4U & (IData)(vlSelfRef.uart__DOT__tx_state))) {
            __Vdly__uart__DOT__tx_state = 0U;
        } else if ((2U & (IData)(vlSelfRef.uart__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.uart__DOT__tx_state))) {
                vlSelfRef.tx = 1U;
                if (VL_GTS_III(32, 7U, vlSelfRef.uart__DOT__tx_clk_count)) {
                    __Vdly__uart__DOT__tx_clk_count 
                        = ((IData)(1U) + vlSelfRef.uart__DOT__tx_clk_count);
                } else {
                    __Vdly__uart__DOT__tx_state = 0U;
                    vlSelfRef.tx_ready = 1U;
                }
            } else {
                vlSelfRef.tx = (1U & ((IData)(vlSelfRef.uart__DOT__tx_shift_reg) 
                                      >> (IData)(vlSelfRef.uart__DOT__tx_bit_idx)));
                if (VL_GTS_III(32, 7U, vlSelfRef.uart__DOT__tx_clk_count)) {
                    __Vdly__uart__DOT__tx_clk_count 
                        = ((IData)(1U) + vlSelfRef.uart__DOT__tx_clk_count);
                } else {
                    __Vdly__uart__DOT__tx_clk_count = 0U;
                    if ((7U > (IData)(vlSelfRef.uart__DOT__tx_bit_idx))) {
                        __Vdly__uart__DOT__tx_bit_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart__DOT__tx_bit_idx)));
                    } else {
                        __Vdly__uart__DOT__tx_state = 3U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.uart__DOT__tx_state))) {
            vlSelfRef.tx = 0U;
            if (VL_GTS_III(32, 7U, vlSelfRef.uart__DOT__tx_clk_count)) {
                __Vdly__uart__DOT__tx_clk_count = ((IData)(1U) 
                                                   + vlSelfRef.uart__DOT__tx_clk_count);
            } else {
                __Vdly__uart__DOT__tx_clk_count = 0U;
                __Vdly__uart__DOT__tx_state = 2U;
                __Vdly__uart__DOT__tx_bit_idx = 0U;
            }
        } else {
            vlSelfRef.tx = 1U;
            vlSelfRef.tx_ready = 1U;
            if (vlSelfRef.tx_en) {
                vlSelfRef.uart__DOT__tx_shift_reg = vlSelfRef.tx_data;
                __Vdly__uart__DOT__tx_state = 1U;
                vlSelfRef.tx_ready = 0U;
                __Vdly__uart__DOT__tx_clk_count = 0U;
            }
        }
    }
    vlSelfRef.uart__DOT__rx_state = __Vdly__uart__DOT__rx_state;
    vlSelfRef.rx_valid = __Vdly__rx_valid;
    vlSelfRef.uart__DOT__rx_clk_count = __Vdly__uart__DOT__rx_clk_count;
    vlSelfRef.uart__DOT__rx_bit_idx = __Vdly__uart__DOT__rx_bit_idx;
    vlSelfRef.uart__DOT__tx_state = __Vdly__uart__DOT__tx_state;
    vlSelfRef.uart__DOT__tx_clk_count = __Vdly__uart__DOT__tx_clk_count;
    vlSelfRef.uart__DOT__tx_bit_idx = __Vdly__uart__DOT__tx_bit_idx;
}

void Vuart___024root___eval_triggers__act(Vuart___024root* vlSelf);

bool Vuart___024root___eval_phase__act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vuart___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vuart___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vuart___024root___eval_phase__nba(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vuart___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__nba(Vuart___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__act(Vuart___024root* vlSelf);
#endif  // VL_DEBUG

void Vuart___024root___eval(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vuart___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/zach/Github/HAL/hw/uart.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vuart___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/zach/Github/HAL/hw/uart.sv", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vuart___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vuart___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vuart___024root___eval_debug_assertions(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelfRef.tx_en & 0xfeU))) {
        Verilated::overWidthError("tx_en");}
    if (VL_UNLIKELY((vlSelfRef.rx & 0xfeU))) {
        Verilated::overWidthError("rx");}
}
#endif  // VL_DEBUG
