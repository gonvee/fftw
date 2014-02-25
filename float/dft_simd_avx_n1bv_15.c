#define SIMD_HEADER "simd-avx.h"
/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Nov 25 07:37:04 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 15 -name n1bv_15 -include n1b.h */

/*
 * This function contains 78 FP additions, 49 FP multiplications,
 * (or, 36 additions, 7 multiplications, 42 fused multiply/add),
 * 78 stack variables, 8 constants, and 30 memory accesses
 */
#include "n1b.h"

static void n1bv_15(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP910592997, +0.910592997310029334643087372129977886038870291);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(30, is), MAKE_VOLATILE_STRIDE(30, os)) {
	       V Tb, TH, Tw, TA, Th, T11, T5, Ti, T12, Ta, Tx, Te, Tq, T16, Tj;
	       V T1, T2, T3;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T3 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
	       {
		    V T6, T7, T8, Tm, Tn, To;
		    T6 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T7 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
		    Tm = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    Tn = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
		    To = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    {
			 V T4, Tc, T9, Td, Tp;
			 Tb = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T4 = VADD(T2, T3);
			 TH = VSUB(T2, T3);
			 Tc = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 Tw = VSUB(T7, T8);
			 T9 = VADD(T7, T8);
			 Td = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Tp = VADD(Tn, To);
			 TA = VSUB(Tn, To);
			 Th = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 T11 = VADD(T1, T4);
			 T5 = VFNMS(LDK(KP500000000), T4, T1);
			 Ti = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 T12 = VADD(T6, T9);
			 Ta = VFNMS(LDK(KP500000000), T9, T6);
			 Tx = VSUB(Tc, Td);
			 Te = VADD(Tc, Td);
			 Tq = VFNMS(LDK(KP500000000), Tp, Tm);
			 T16 = VADD(Tm, Tp);
			 Tj = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    }
	       }
	       {
		    V TI, Ty, T13, Tf, Tz, Tk;
		    TI = VADD(Tw, Tx);
		    Ty = VSUB(Tw, Tx);
		    T13 = VADD(Tb, Te);
		    Tf = VFNMS(LDK(KP500000000), Te, Tb);
		    Tz = VSUB(Ti, Tj);
		    Tk = VADD(Ti, Tj);
		    {
			 V T1d, T14, Tg, TE, TJ, TB, T15, Tl;
			 T1d = VSUB(T12, T13);
			 T14 = VADD(T12, T13);
			 Tg = VADD(Ta, Tf);
			 TE = VSUB(Ta, Tf);
			 TJ = VADD(Tz, TA);
			 TB = VSUB(Tz, TA);
			 T15 = VADD(Th, Tk);
			 Tl = VFNMS(LDK(KP500000000), Tk, Th);
			 {
			      V TM, TK, TS, TC, T1c, T17, Tr, TF, TL, T10;
			      TM = VSUB(TI, TJ);
			      TK = VADD(TI, TJ);
			      TS = VFNMS(LDK(KP618033988), Ty, TB);
			      TC = VFMA(LDK(KP618033988), TB, Ty);
			      T1c = VSUB(T15, T16);
			      T17 = VADD(T15, T16);
			      Tr = VADD(Tl, Tq);
			      TF = VSUB(Tl, Tq);
			      TL = VFNMS(LDK(KP250000000), TK, TH);
			      T10 = VMUL(LDK(KP866025403), VADD(TH, TK));
			      {
				   V T1g, T1e, T1a, Tu, Ts, TU, TG, TV, TN, T19, T18, Tt, TZ;
				   T1g = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1c, T1d));
				   T1e = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1d, T1c));
				   T18 = VADD(T14, T17);
				   T1a = VSUB(T14, T17);
				   Tu = VSUB(Tg, Tr);
				   Ts = VADD(Tg, Tr);
				   TU = VFNMS(LDK(KP618033988), TE, TF);
				   TG = VFMA(LDK(KP618033988), TF, TE);
				   TV = VFNMS(LDK(KP559016994), TM, TL);
				   TN = VFMA(LDK(KP559016994), TM, TL);
				   ST(&(xo[0]), VADD(T11, T18), ovs, &(xo[0]));
				   T19 = VFNMS(LDK(KP250000000), T18, T11);
				   Tt = VFNMS(LDK(KP250000000), Ts, T5);
				   TZ = VADD(T5, Ts);
				   {
					V TW, TY, TQ, TO, T1b, T1f, TR, Tv;
					TW = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), TV, TU));
					TY = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), TV, TU));
					TQ = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), TN, TG));
					TO = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), TN, TG));
					T1b = VFNMS(LDK(KP559016994), T1a, T19);
					T1f = VFMA(LDK(KP559016994), T1a, T19);
					TR = VFNMS(LDK(KP559016994), Tu, Tt);
					Tv = VFMA(LDK(KP559016994), Tu, Tt);
					ST(&(xo[WS(os, 10)]), VFMAI(T10, TZ), ovs, &(xo[0]));
					ST(&(xo[WS(os, 5)]), VFNMSI(T10, TZ), ovs, &(xo[WS(os, 1)]));
					{
					     V TT, TX, TP, TD;
					     ST(&(xo[WS(os, 12)]), VFNMSI(T1e, T1b), ovs, &(xo[0]));
					     ST(&(xo[WS(os, 3)]), VFMAI(T1e, T1b), ovs, &(xo[WS(os, 1)]));
					     ST(&(xo[WS(os, 9)]), VFNMSI(T1g, T1f), ovs, &(xo[WS(os, 1)]));
					     ST(&(xo[WS(os, 6)]), VFMAI(T1g, T1f), ovs, &(xo[0]));
					     TT = VFNMS(LDK(KP823639103), TS, TR);
					     TX = VFMA(LDK(KP823639103), TS, TR);
					     TP = VFMA(LDK(KP823639103), TC, Tv);
					     TD = VFNMS(LDK(KP823639103), TC, Tv);
					     ST(&(xo[WS(os, 13)]), VFMAI(TW, TT), ovs, &(xo[WS(os, 1)]));
					     ST(&(xo[WS(os, 2)]), VFNMSI(TW, TT), ovs, &(xo[0]));
					     ST(&(xo[WS(os, 8)]), VFMAI(TY, TX), ovs, &(xo[0]));
					     ST(&(xo[WS(os, 7)]), VFNMSI(TY, TX), ovs, &(xo[WS(os, 1)]));
					     ST(&(xo[WS(os, 11)]), VFMAI(TQ, TP), ovs, &(xo[WS(os, 1)]));
					     ST(&(xo[WS(os, 4)]), VFNMSI(TQ, TP), ovs, &(xo[0]));
					     ST(&(xo[WS(os, 14)]), VFNMSI(TO, TD), ovs, &(xo[0]));
					     ST(&(xo[WS(os, 1)]), VFMAI(TO, TD), ovs, &(xo[WS(os, 1)]));
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 15, XSIMD_STRING("n1bv_15"), {36, 7, 42, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_15) (planner *p) {
     X(kdft_register) (p, n1bv_15, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 15 -name n1bv_15 -include n1b.h */

/*
 * This function contains 78 FP additions, 25 FP multiplications,
 * (or, 64 additions, 11 multiplications, 14 fused multiply/add),
 * 55 stack variables, 10 constants, and 30 memory accesses
 */
#include "n1b.h"

static void n1bv_15(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP216506350, +0.216506350946109661690930792688234045867850657);
     DVK(KP509036960, +0.509036960455127183450980863393907648510733164);
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP484122918, +0.484122918275927110647408174972799951354115213);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(30, is), MAKE_VOLATILE_STRIDE(30, os)) {
	       V Ti, T11, TH, Ts, TL, TM, Tz, TC, TD, TI, T12, T13, T14, T15, T16;
	       V T17, Tf, Tj, TZ, T10;
	       {
		    V TF, Tg, Th, TG;
		    TF = LD(&(xi[0]), ivs, &(xi[0]));
		    Tg = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Th = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    TG = VADD(Tg, Th);
		    Ti = VSUB(Tg, Th);
		    T11 = VADD(TF, TG);
		    TH = VFNMS(LDK(KP500000000), TG, TF);
	       }
	       {
		    V Tm, Tn, T3, To, Tw, Tx, Td, Ty, Tp, Tq, T6, Tr, Tt, Tu, Ta;
		    V Tv, T7, Te;
		    {
			 V T1, T2, Tb, Tc;
			 Tm = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T1 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T2 = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Tn = VADD(T1, T2);
			 T3 = VSUB(T1, T2);
			 To = VFNMS(LDK(KP500000000), Tn, Tm);
			 Tw = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 Tb = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tx = VADD(Tb, Tc);
			 Td = VSUB(Tb, Tc);
			 Ty = VFNMS(LDK(KP500000000), Tx, Tw);
		    }
		    {
			 V T4, T5, T8, T9;
			 Tp = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Tq = VADD(T4, T5);
			 T6 = VSUB(T4, T5);
			 Tr = VFNMS(LDK(KP500000000), Tq, Tp);
			 Tt = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 T9 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tu = VADD(T8, T9);
			 Ta = VSUB(T8, T9);
			 Tv = VFNMS(LDK(KP500000000), Tu, Tt);
		    }
		    Ts = VSUB(To, Tr);
		    TL = VSUB(T3, T6);
		    TM = VSUB(Ta, Td);
		    Tz = VSUB(Tv, Ty);
		    TC = VADD(To, Tr);
		    TD = VADD(Tv, Ty);
		    TI = VADD(TC, TD);
		    T12 = VADD(Tm, Tn);
		    T13 = VADD(Tp, Tq);
		    T14 = VADD(T12, T13);
		    T15 = VADD(Tt, Tu);
		    T16 = VADD(Tw, Tx);
		    T17 = VADD(T15, T16);
		    T7 = VADD(T3, T6);
		    Te = VADD(Ta, Td);
		    Tf = VMUL(LDK(KP484122918), VSUB(T7, Te));
		    Tj = VADD(T7, Te);
	       }
	       TZ = VADD(TH, TI);
	       T10 = VBYI(VMUL(LDK(KP866025403), VADD(Ti, Tj)));
	       ST(&(xo[WS(os, 5)]), VSUB(TZ, T10), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 10)]), VADD(T10, TZ), ovs, &(xo[0]));
	       {
		    V T1a, T18, T19, T1e, T1f, T1c, T1d, T1g, T1b;
		    T1a = VMUL(LDK(KP559016994), VSUB(T14, T17));
		    T18 = VADD(T14, T17);
		    T19 = VFNMS(LDK(KP250000000), T18, T11);
		    T1c = VSUB(T12, T13);
		    T1d = VSUB(T15, T16);
		    T1e = VBYI(VFNMS(LDK(KP951056516), T1d, VMUL(LDK(KP587785252), T1c)));
		    T1f = VBYI(VFMA(LDK(KP951056516), T1c, VMUL(LDK(KP587785252), T1d)));
		    ST(&(xo[0]), VADD(T11, T18), ovs, &(xo[0]));
		    T1g = VADD(T1a, T19);
		    ST(&(xo[WS(os, 6)]), VADD(T1f, T1g), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 9)]), VSUB(T1g, T1f), ovs, &(xo[WS(os, 1)]));
		    T1b = VSUB(T19, T1a);
		    ST(&(xo[WS(os, 3)]), VSUB(T1b, T1e), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 12)]), VADD(T1e, T1b), ovs, &(xo[0]));
	       }
	       {
		    V TA, TN, TU, TS, Tl, TR, TK, TV, Tk, TE, TJ;
		    TA = VFMA(LDK(KP951056516), Ts, VMUL(LDK(KP587785252), Tz));
		    TN = VFMA(LDK(KP823639103), TL, VMUL(LDK(KP509036960), TM));
		    TU = VFNMS(LDK(KP823639103), TM, VMUL(LDK(KP509036960), TL));
		    TS = VFNMS(LDK(KP951056516), Tz, VMUL(LDK(KP587785252), Ts));
		    Tk = VFNMS(LDK(KP216506350), Tj, VMUL(LDK(KP866025403), Ti));
		    Tl = VADD(Tf, Tk);
		    TR = VSUB(Tf, Tk);
		    TE = VMUL(LDK(KP559016994), VSUB(TC, TD));
		    TJ = VFNMS(LDK(KP250000000), TI, TH);
		    TK = VADD(TE, TJ);
		    TV = VSUB(TJ, TE);
		    {
			 V TB, TO, TX, TY;
			 TB = VBYI(VADD(Tl, TA));
			 TO = VSUB(TK, TN);
			 ST(&(xo[WS(os, 1)]), VADD(TB, TO), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 14)]), VSUB(TO, TB), ovs, &(xo[0]));
			 TX = VBYI(VSUB(TS, TR));
			 TY = VSUB(TV, TU);
			 ST(&(xo[WS(os, 7)]), VADD(TX, TY), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 8)]), VSUB(TY, TX), ovs, &(xo[0]));
		    }
		    {
			 V TP, TQ, TT, TW;
			 TP = VBYI(VSUB(Tl, TA));
			 TQ = VADD(TN, TK);
			 ST(&(xo[WS(os, 4)]), VADD(TP, TQ), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 11)]), VSUB(TQ, TP), ovs, &(xo[WS(os, 1)]));
			 TT = VBYI(VADD(TR, TS));
			 TW = VADD(TU, TV);
			 ST(&(xo[WS(os, 2)]), VADD(TT, TW), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 13)]), VSUB(TW, TT), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 15, XSIMD_STRING("n1bv_15"), {64, 11, 14, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_15) (planner *p) {
     X(kdft_register) (p, n1bv_15, &desc);
}

#endif				/* HAVE_FMA */
