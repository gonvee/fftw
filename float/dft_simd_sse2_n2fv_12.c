#define SIMD_HEADER "simd-sse2.h"
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
/* Generated on Sun Nov 25 07:37:22 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 12 -name n2fv_12 -with-ostride 2 -include n2f.h -store-multiple 2 */

/*
 * This function contains 48 FP additions, 20 FP multiplications,
 * (or, 30 additions, 2 multiplications, 18 fused multiply/add),
 * 61 stack variables, 2 constants, and 30 memory accesses
 */
#include "n2f.h"

static void n2fv_12(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(24, is), MAKE_VOLATILE_STRIDE(24, os)) {
	       V T1, T6, Tk, Tn, Tc, Td, Tf, Tr, T4, Ts, T9, Tg, Te, Tl;
	       {
		    V T2, T3, T7, T8;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T6 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T3 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Tk = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Tn = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Td = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    Tf = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Tr = VSUB(T3, T2);
		    T4 = VADD(T2, T3);
		    Ts = VSUB(T8, T7);
		    T9 = VADD(T7, T8);
		    Tg = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       }
	       Te = VSUB(Tc, Td);
	       Tl = VADD(Td, Tc);
	       {
		    V T5, TF, TB, Tt, Ta, TG, Th, To, Tm, TI;
		    T5 = VFNMS(LDK(KP500000000), T4, T1);
		    TF = VADD(T1, T4);
		    TB = VADD(Tr, Ts);
		    Tt = VSUB(Tr, Ts);
		    Ta = VFNMS(LDK(KP500000000), T9, T6);
		    TG = VADD(T6, T9);
		    Th = VSUB(Tf, Tg);
		    To = VADD(Tf, Tg);
		    Tm = VFNMS(LDK(KP500000000), Tl, Tk);
		    TI = VADD(Tk, Tl);
		    {
			 V TH, TL, Tb, Tx, TJ, Tp, Ti, TA;
			 TH = VSUB(TF, TG);
			 TL = VADD(TF, TG);
			 Tb = VSUB(T5, Ta);
			 Tx = VADD(T5, Ta);
			 TJ = VADD(Tn, To);
			 Tp = VFNMS(LDK(KP500000000), To, Tn);
			 Ti = VADD(Te, Th);
			 TA = VSUB(Te, Th);
			 {
			      V Tq, Ty, TK, TM;
			      Tq = VSUB(Tm, Tp);
			      Ty = VADD(Tm, Tp);
			      TK = VSUB(TI, TJ);
			      TM = VADD(TI, TJ);
			      {
				   V TC, TE, Tj, Tv;
				   TC = VMUL(LDK(KP866025403), VSUB(TA, TB));
				   TE = VMUL(LDK(KP866025403), VADD(TB, TA));
				   Tj = VFMA(LDK(KP866025403), Ti, Tb);
				   Tv = VFNMS(LDK(KP866025403), Ti, Tb);
				   {
					V Tz, TD, Tu, Tw;
					Tz = VSUB(Tx, Ty);
					TD = VADD(Tx, Ty);
					Tu = VFNMS(LDK(KP866025403), Tt, Tq);
					Tw = VFMA(LDK(KP866025403), Tt, Tq);
					{
					     V TN, TO, TP, TQ;
					     TN = VADD(TL, TM);
					     STM2(&(xo[0]), TN, ovs, &(xo[0]));
					     TO = VSUB(TL, TM);
					     STM2(&(xo[12]), TO, ovs, &(xo[0]));
					     TP = VFMAI(TK, TH);
					     STM2(&(xo[6]), TP, ovs, &(xo[2]));
					     TQ = VFNMSI(TK, TH);
					     STM2(&(xo[18]), TQ, ovs, &(xo[2]));
					     {
						  V TR, TS, TT, TU;
						  TR = VFMAI(TE, TD);
						  STM2(&(xo[8]), TR, ovs, &(xo[0]));
						  TS = VFNMSI(TE, TD);
						  STM2(&(xo[16]), TS, ovs, &(xo[0]));
						  STN2(&(xo[16]), TS, TQ, ovs);
						  TT = VFNMSI(TC, Tz);
						  STM2(&(xo[20]), TT, ovs, &(xo[0]));
						  TU = VFMAI(TC, Tz);
						  STM2(&(xo[4]), TU, ovs, &(xo[0]));
						  STN2(&(xo[4]), TU, TP, ovs);
						  {
						       V TV, TW, TX, TY;
						       TV = VFNMSI(Tw, Tv);
						       STM2(&(xo[10]), TV, ovs, &(xo[2]));
						       STN2(&(xo[8]), TR, TV, ovs);
						       TW = VFMAI(Tw, Tv);
						       STM2(&(xo[14]), TW, ovs, &(xo[2]));
						       STN2(&(xo[12]), TO, TW, ovs);
						       TX = VFMAI(Tu, Tj);
						       STM2(&(xo[22]), TX, ovs, &(xo[2]));
						       STN2(&(xo[20]), TT, TX, ovs);
						       TY = VFNMSI(Tu, Tj);
						       STM2(&(xo[2]), TY, ovs, &(xo[2]));
						       STN2(&(xo[0]), TN, TY, ovs);
						  }
					     }
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

static const kdft_desc desc = { 12, XSIMD_STRING("n2fv_12"), {30, 2, 18, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2fv_12) (planner *p) {
     X(kdft_register) (p, n2fv_12, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 12 -name n2fv_12 -with-ostride 2 -include n2f.h -store-multiple 2 */

/*
 * This function contains 48 FP additions, 8 FP multiplications,
 * (or, 44 additions, 4 multiplications, 4 fused multiply/add),
 * 33 stack variables, 2 constants, and 30 memory accesses
 */
#include "n2f.h"

static void n2fv_12(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(24, is), MAKE_VOLATILE_STRIDE(24, os)) {
	       V T5, Ta, TJ, Ty, Tq, Tp, Tg, Tl, TI, TA, Tz, Tu;
	       {
		    V T1, T6, T4, Tw, T9, Tx;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T6 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    {
			 V T2, T3, T7, T8;
			 T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T3 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T4 = VADD(T2, T3);
			 Tw = VSUB(T3, T2);
			 T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T9 = VADD(T7, T8);
			 Tx = VSUB(T8, T7);
		    }
		    T5 = VADD(T1, T4);
		    Ta = VADD(T6, T9);
		    TJ = VADD(Tw, Tx);
		    Ty = VMUL(LDK(KP866025403), VSUB(Tw, Tx));
		    Tq = VFNMS(LDK(KP500000000), T9, T6);
		    Tp = VFNMS(LDK(KP500000000), T4, T1);
	       }
	       {
		    V Tc, Th, Tf, Ts, Tk, Tt;
		    Tc = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Th = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    {
			 V Td, Te, Ti, Tj;
			 Td = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Te = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Tf = VADD(Td, Te);
			 Ts = VSUB(Te, Td);
			 Ti = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tj = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 Tk = VADD(Ti, Tj);
			 Tt = VSUB(Tj, Ti);
		    }
		    Tg = VADD(Tc, Tf);
		    Tl = VADD(Th, Tk);
		    TI = VADD(Ts, Tt);
		    TA = VFNMS(LDK(KP500000000), Tk, Th);
		    Tz = VFNMS(LDK(KP500000000), Tf, Tc);
		    Tu = VMUL(LDK(KP866025403), VSUB(Ts, Tt));
	       }
	       {
		    V TN, TO, TP, TQ, TR, TS;
		    {
			 V Tb, Tm, Tn, To;
			 Tb = VSUB(T5, Ta);
			 Tm = VBYI(VSUB(Tg, Tl));
			 TN = VSUB(Tb, Tm);
			 STM2(&(xo[18]), TN, ovs, &(xo[2]));
			 TO = VADD(Tb, Tm);
			 STM2(&(xo[6]), TO, ovs, &(xo[2]));
			 Tn = VADD(T5, Ta);
			 To = VADD(Tg, Tl);
			 TP = VSUB(Tn, To);
			 STM2(&(xo[12]), TP, ovs, &(xo[0]));
			 TQ = VADD(Tn, To);
			 STM2(&(xo[0]), TQ, ovs, &(xo[0]));
		    }
		    {
			 V Tv, TE, TC, TD, Tr, TB, TT, TU;
			 Tr = VSUB(Tp, Tq);
			 Tv = VSUB(Tr, Tu);
			 TE = VADD(Tr, Tu);
			 TB = VSUB(Tz, TA);
			 TC = VBYI(VADD(Ty, TB));
			 TD = VBYI(VSUB(Ty, TB));
			 TR = VSUB(Tv, TC);
			 STM2(&(xo[10]), TR, ovs, &(xo[2]));
			 TS = VSUB(TE, TD);
			 STM2(&(xo[22]), TS, ovs, &(xo[2]));
			 TT = VADD(TC, Tv);
			 STM2(&(xo[14]), TT, ovs, &(xo[2]));
			 STN2(&(xo[12]), TP, TT, ovs);
			 TU = VADD(TD, TE);
			 STM2(&(xo[2]), TU, ovs, &(xo[2]));
			 STN2(&(xo[0]), TQ, TU, ovs);
		    }
		    {
			 V TK, TM, TH, TL, TF, TG;
			 TK = VBYI(VMUL(LDK(KP866025403), VSUB(TI, TJ)));
			 TM = VBYI(VMUL(LDK(KP866025403), VADD(TJ, TI)));
			 TF = VADD(Tp, Tq);
			 TG = VADD(Tz, TA);
			 TH = VSUB(TF, TG);
			 TL = VADD(TF, TG);
			 {
			      V TV, TW, TX, TY;
			      TV = VSUB(TH, TK);
			      STM2(&(xo[20]), TV, ovs, &(xo[0]));
			      STN2(&(xo[20]), TV, TS, ovs);
			      TW = VADD(TL, TM);
			      STM2(&(xo[8]), TW, ovs, &(xo[0]));
			      STN2(&(xo[8]), TW, TR, ovs);
			      TX = VADD(TH, TK);
			      STM2(&(xo[4]), TX, ovs, &(xo[0]));
			      STN2(&(xo[4]), TX, TO, ovs);
			      TY = VSUB(TL, TM);
			      STM2(&(xo[16]), TY, ovs, &(xo[0]));
			      STN2(&(xo[16]), TY, TN, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 12, XSIMD_STRING("n2fv_12"), {44, 4, 4, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2fv_12) (planner *p) {
     X(kdft_register) (p, n2fv_12, &desc);
}

#endif				/* HAVE_FMA */
