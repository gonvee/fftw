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
/* Generated on Sun Nov 25 07:38:55 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 20 -name t3fv_20 -include t3f.h */

/*
 * This function contains 138 FP additions, 118 FP multiplications,
 * (or, 92 additions, 72 multiplications, 46 fused multiply/add),
 * 90 stack variables, 4 constants, and 40 memory accesses
 */
#include "t3f.h"

static void t3fv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T1k, T1w, T1r, T1z, T1o, T1y, T1v, T1h;
	       {
		    V T2, T8, T3, Td;
		    T2 = LDW(&(W[0]));
		    T8 = LDW(&(W[TWVL * 2]));
		    T3 = LDW(&(W[TWVL * 4]));
		    Td = LDW(&(W[TWVL * 6]));
		    {
			 V T7, TM, T1F, T23, T1p, Tp, T1j, T27, T1P, T1I, T1i, T1L, T28, T1S, T1q;
			 V TE, T1n, T1d, T26, T2e;
			 {
			      V T1, TK, T5, TH;
			      T1 = LD(&(x[0]), ms, &(x[0]));
			      TK = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			      T5 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			      TH = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			      {
				   V TA, Tx, TU, T1O, T14, Th, T1G, T1R, T1b, T1J, To, Ts, TV, Tv, TO;
				   V TQ, TT, Ty, TB;
				   {
					V Tq, Tt, T17, T1a, Tk, Tn;
					{
					     V Tl, Ti, T15, T18, TZ, Tc, T6, Tb, Tf, T10, T12, TL;
					     {
						  V TJ, Ta, T9, T4;
						  Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
						  TA = VZMULJ(T2, T8);
						  T9 = VZMUL(T2, T8);
						  Tx = VZMUL(T8, T3);
						  Tl = VZMULJ(T8, T3);
						  T4 = VZMUL(T2, T3);
						  Tq = VZMULJ(T2, T3);
						  Tt = VZMULJ(T2, Td);
						  Ti = VZMULJ(T8, Td);
						  T15 = VZMULJ(TA, Td);
						  T18 = VZMULJ(TA, T3);
						  TU = VZMUL(TA, T3);
						  TJ = VZMULJ(T9, Td);
						  TZ = VZMUL(T9, T3);
						  Tc = VZMULJ(T9, T3);
						  T6 = VZMULJ(T4, T5);
						  Tb = VZMULJ(T9, Ta);
						  Tf = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
						  T10 = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
						  T12 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
						  TL = VZMULJ(TJ, TK);
					     }
					     {
						  V T1D, T11, T13, T19, T1E, Tg, T16, TI, Te, Tj, Tm;
						  T16 = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
						  TI = VZMULJ(Tc, TH);
						  Te = VZMULJ(Tc, Td);
						  T7 = VSUB(T1, T6);
						  T1D = VADD(T1, T6);
						  T11 = VZMULJ(TZ, T10);
						  T13 = VZMULJ(T8, T12);
						  T19 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
						  T17 = VZMULJ(T15, T16);
						  TM = VSUB(TI, TL);
						  T1E = VADD(TI, TL);
						  Tg = VZMULJ(Te, Tf);
						  Tj = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
						  Tm = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
						  T1O = VADD(T11, T13);
						  T14 = VSUB(T11, T13);
						  T1a = VZMULJ(T18, T19);
						  T1F = VSUB(T1D, T1E);
						  T23 = VADD(T1D, T1E);
						  Th = VSUB(Tb, Tg);
						  T1G = VADD(Tb, Tg);
						  Tk = VZMULJ(Ti, Tj);
						  Tn = VZMULJ(Tl, Tm);
					     }
					}
					{
					     V Tr, Tu, TN, TP, TS;
					     Tr = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
					     T1R = VADD(T17, T1a);
					     T1b = VSUB(T17, T1a);
					     Tu = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
					     TN = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
					     TP = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
					     TS = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
					     T1J = VADD(Tk, Tn);
					     To = VSUB(Tk, Tn);
					     Ts = VZMULJ(Tq, Tr);
					     TV = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
					     Tv = VZMULJ(Tt, Tu);
					     TO = VZMULJ(T3, TN);
					     TQ = VZMULJ(Td, TP);
					     TT = VZMULJ(T2, TS);
					     Ty = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
					     TB = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
					}
				   }
				   {
					V T1N, Tw, T1H, TR, Tz, TC, T1c, TX, T1K, TW;
					T1p = VSUB(Th, To);
					Tp = VADD(Th, To);
					TW = VZMULJ(TU, TV);
					T1N = VADD(Ts, Tv);
					Tw = VSUB(Ts, Tv);
					T1H = VADD(TO, TQ);
					TR = VSUB(TO, TQ);
					Tz = VZMULJ(Tx, Ty);
					TC = VZMULJ(TA, TB);
					T1j = VSUB(T1b, T14);
					T1c = VADD(T14, T1b);
					TX = VSUB(TT, TW);
					T1K = VADD(TT, TW);
					T27 = VADD(T1N, T1O);
					T1P = VSUB(T1N, T1O);
					{
					     V TD, T1Q, T24, TY, T25;
					     TD = VSUB(Tz, TC);
					     T1Q = VADD(Tz, TC);
					     T1I = VSUB(T1G, T1H);
					     T24 = VADD(T1G, T1H);
					     TY = VADD(TR, TX);
					     T1i = VSUB(TX, TR);
					     T25 = VADD(T1J, T1K);
					     T1L = VSUB(T1J, T1K);
					     T28 = VADD(T1Q, T1R);
					     T1S = VSUB(T1Q, T1R);
					     T1q = VSUB(Tw, TD);
					     TE = VADD(Tw, TD);
					     T1n = VSUB(T1c, TY);
					     T1d = VADD(TY, T1c);
					     T26 = VADD(T24, T25);
					     T2e = VSUB(T24, T25);
					}
				   }
			      }
			 }
			 {
			      V T1M, T1Z, T1Y, T1T, T29, T2f, T1g, TF, T1m, T1e;
			      T1M = VADD(T1I, T1L);
			      T1Z = VSUB(T1I, T1L);
			      T1Y = VSUB(T1P, T1S);
			      T1T = VADD(T1P, T1S);
			      T29 = VADD(T27, T28);
			      T2f = VSUB(T27, T28);
			      T1g = VSUB(Tp, TE);
			      TF = VADD(Tp, TE);
			      T1m = VFNMS(LDK(KP250000000), T1d, TM);
			      T1e = VADD(TM, T1d);
			      {
				   V T1W, T2c, T1f, T2i, T2g, T22, T20, T1V, T2b, T1U, T2a, TG;
				   T1k = VFMA(LDK(KP618033988), T1j, T1i);
				   T1w = VFNMS(LDK(KP618033988), T1i, T1j);
				   T1W = VSUB(T1M, T1T);
				   T1U = VADD(T1M, T1T);
				   T2c = VSUB(T26, T29);
				   T2a = VADD(T26, T29);
				   T1f = VFNMS(LDK(KP250000000), TF, T7);
				   TG = VADD(T7, TF);
				   T2i = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T2e, T2f));
				   T2g = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T2f, T2e));
				   T22 = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1Y, T1Z));
				   T20 = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1Z, T1Y));
				   ST(&(x[WS(rs, 10)]), VADD(T1F, T1U), ms, &(x[0]));
				   T1V = VFNMS(LDK(KP250000000), T1U, T1F);
				   ST(&(x[0]), VADD(T23, T2a), ms, &(x[0]));
				   T2b = VFNMS(LDK(KP250000000), T2a, T23);
				   ST(&(x[WS(rs, 15)]), VFMAI(T1e, TG), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 5)]), VFNMSI(T1e, TG), ms, &(x[WS(rs, 1)]));
				   T1r = VFMA(LDK(KP618033988), T1q, T1p);
				   T1z = VFNMS(LDK(KP618033988), T1p, T1q);
				   {
					V T21, T1X, T2h, T2d;
					T21 = VFMA(LDK(KP559016994), T1W, T1V);
					T1X = VFNMS(LDK(KP559016994), T1W, T1V);
					T2h = VFNMS(LDK(KP559016994), T2c, T2b);
					T2d = VFMA(LDK(KP559016994), T2c, T2b);
					ST(&(x[WS(rs, 18)]), VFNMSI(T20, T1X), ms, &(x[0]));
					ST(&(x[WS(rs, 2)]), VFMAI(T20, T1X), ms, &(x[0]));
					ST(&(x[WS(rs, 14)]), VFMAI(T22, T21), ms, &(x[0]));
					ST(&(x[WS(rs, 6)]), VFNMSI(T22, T21), ms, &(x[0]));
					ST(&(x[WS(rs, 16)]), VFNMSI(T2g, T2d), ms, &(x[0]));
					ST(&(x[WS(rs, 4)]), VFMAI(T2g, T2d), ms, &(x[0]));
					ST(&(x[WS(rs, 12)]), VFMAI(T2i, T2h), ms, &(x[0]));
					ST(&(x[WS(rs, 8)]), VFNMSI(T2i, T2h), ms, &(x[0]));
					T1o = VFNMS(LDK(KP559016994), T1n, T1m);
					T1y = VFMA(LDK(KP559016994), T1n, T1m);
					T1v = VFNMS(LDK(KP559016994), T1g, T1f);
					T1h = VFMA(LDK(KP559016994), T1g, T1f);
				   }
			      }
			 }
		    }
	       }
	       {
		    V T1C, T1A, T1s, T1u, T1l, T1t, T1B, T1x;
		    T1C = VFMA(LDK(KP951056516), T1z, T1y);
		    T1A = VFNMS(LDK(KP951056516), T1z, T1y);
		    T1s = VFMA(LDK(KP951056516), T1r, T1o);
		    T1u = VFNMS(LDK(KP951056516), T1r, T1o);
		    T1l = VFMA(LDK(KP951056516), T1k, T1h);
		    T1t = VFNMS(LDK(KP951056516), T1k, T1h);
		    T1B = VFMA(LDK(KP951056516), T1w, T1v);
		    T1x = VFNMS(LDK(KP951056516), T1w, T1v);
		    ST(&(x[WS(rs, 11)]), VFMAI(T1u, T1t), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 9)]), VFNMSI(T1u, T1t), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 19)]), VFMAI(T1s, T1l), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VFNMSI(T1s, T1l), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VFMAI(T1A, T1x), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 17)]), VFNMSI(T1A, T1x), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 7)]), VFMAI(T1C, T1B), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 13)]), VFNMSI(T1C, T1B), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 19),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 20, XSIMD_STRING("t3fv_20"), twinstr, &GENUS, {92, 72, 46, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_20) (planner *p) {
     X(kdft_dit_register) (p, t3fv_20, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 20 -name t3fv_20 -include t3f.h */

/*
 * This function contains 138 FP additions, 92 FP multiplications,
 * (or, 126 additions, 80 multiplications, 12 fused multiply/add),
 * 73 stack variables, 4 constants, and 40 memory accesses
 */
#include "t3f.h"

static void t3fv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T2, T8, T9, TA, T3, Tc, T4, TZ, T18, Tl, Tq, Tx, TU, Td, Te;
	       V T15, Ti, Tt, TJ;
	       T2 = LDW(&(W[0]));
	       T8 = LDW(&(W[TWVL * 2]));
	       T9 = VZMUL(T2, T8);
	       TA = VZMULJ(T2, T8);
	       T3 = LDW(&(W[TWVL * 4]));
	       Tc = VZMULJ(T9, T3);
	       T4 = VZMUL(T2, T3);
	       TZ = VZMUL(T9, T3);
	       T18 = VZMULJ(TA, T3);
	       Tl = VZMULJ(T8, T3);
	       Tq = VZMULJ(T2, T3);
	       Tx = VZMUL(T8, T3);
	       TU = VZMUL(TA, T3);
	       Td = LDW(&(W[TWVL * 6]));
	       Te = VZMULJ(Tc, Td);
	       T15 = VZMULJ(TA, Td);
	       Ti = VZMULJ(T8, Td);
	       Tt = VZMULJ(T2, Td);
	       TJ = VZMULJ(T9, Td);
	       {
		    V T7, TM, T1U, T2d, T1i, T1p, T1q, T1j, Tp, TE, TF, T26, T27, T2b, T1M;
		    V T1P, T1V, TY, T1c, T1d, T23, T24, T2a, T1F, T1I, T1W, TG, T1e;
		    {
			 V T1, TL, T6, TI, TK, T5, TH, T1S, T1T;
			 T1 = LD(&(x[0]), ms, &(x[0]));
			 TK = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			 TL = VZMULJ(TJ, TK);
			 T5 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			 T6 = VZMULJ(T4, T5);
			 TH = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 TI = VZMULJ(Tc, TH);
			 T7 = VSUB(T1, T6);
			 TM = VSUB(TI, TL);
			 T1S = VADD(T1, T6);
			 T1T = VADD(TI, TL);
			 T1U = VSUB(T1S, T1T);
			 T2d = VADD(T1S, T1T);
		    }
		    {
			 V Th, T1K, T14, T1E, T1b, T1H, To, T1N, Tw, T1D, TR, T1L, TX, T1O, TD;
			 V T1G;
			 {
			      V Tb, Tg, Ta, Tf;
			      Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			      Tb = VZMULJ(T9, Ta);
			      Tf = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			      Tg = VZMULJ(Te, Tf);
			      Th = VSUB(Tb, Tg);
			      T1K = VADD(Tb, Tg);
			 }
			 {
			      V T11, T13, T10, T12;
			      T10 = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			      T11 = VZMULJ(TZ, T10);
			      T12 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			      T13 = VZMULJ(T8, T12);
			      T14 = VSUB(T11, T13);
			      T1E = VADD(T11, T13);
			 }
			 {
			      V T17, T1a, T16, T19;
			      T16 = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			      T17 = VZMULJ(T15, T16);
			      T19 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			      T1a = VZMULJ(T18, T19);
			      T1b = VSUB(T17, T1a);
			      T1H = VADD(T17, T1a);
			 }
			 {
			      V Tk, Tn, Tj, Tm;
			      Tj = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			      Tk = VZMULJ(Ti, Tj);
			      Tm = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			      Tn = VZMULJ(Tl, Tm);
			      To = VSUB(Tk, Tn);
			      T1N = VADD(Tk, Tn);
			 }
			 {
			      V Ts, Tv, Tr, Tu;
			      Tr = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			      Ts = VZMULJ(Tq, Tr);
			      Tu = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			      Tv = VZMULJ(Tt, Tu);
			      Tw = VSUB(Ts, Tv);
			      T1D = VADD(Ts, Tv);
			 }
			 {
			      V TO, TQ, TN, TP;
			      TN = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			      TO = VZMULJ(T3, TN);
			      TP = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
			      TQ = VZMULJ(Td, TP);
			      TR = VSUB(TO, TQ);
			      T1L = VADD(TO, TQ);
			 }
			 {
			      V TT, TW, TS, TV;
			      TS = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			      TT = VZMULJ(T2, TS);
			      TV = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			      TW = VZMULJ(TU, TV);
			      TX = VSUB(TT, TW);
			      T1O = VADD(TT, TW);
			 }
			 {
			      V Tz, TC, Ty, TB;
			      Ty = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			      Tz = VZMULJ(Tx, Ty);
			      TB = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      TC = VZMULJ(TA, TB);
			      TD = VSUB(Tz, TC);
			      T1G = VADD(Tz, TC);
			 }
			 T1i = VSUB(TX, TR);
			 T1p = VSUB(Th, To);
			 T1q = VSUB(Tw, TD);
			 T1j = VSUB(T1b, T14);
			 Tp = VADD(Th, To);
			 TE = VADD(Tw, TD);
			 TF = VADD(Tp, TE);
			 T26 = VADD(T1D, T1E);
			 T27 = VADD(T1G, T1H);
			 T2b = VADD(T26, T27);
			 T1M = VSUB(T1K, T1L);
			 T1P = VSUB(T1N, T1O);
			 T1V = VADD(T1M, T1P);
			 TY = VADD(TR, TX);
			 T1c = VADD(T14, T1b);
			 T1d = VADD(TY, T1c);
			 T23 = VADD(T1K, T1L);
			 T24 = VADD(T1N, T1O);
			 T2a = VADD(T23, T24);
			 T1F = VSUB(T1D, T1E);
			 T1I = VSUB(T1G, T1H);
			 T1W = VADD(T1F, T1I);
		    }
		    TG = VADD(T7, TF);
		    T1e = VBYI(VADD(TM, T1d));
		    ST(&(x[WS(rs, 5)]), VSUB(TG, T1e), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 15)]), VADD(TG, T1e), ms, &(x[WS(rs, 1)]));
		    {
			 V T2c, T2e, T2f, T29, T2i, T25, T28, T2h, T2g;
			 T2c = VMUL(LDK(KP559016994), VSUB(T2a, T2b));
			 T2e = VADD(T2a, T2b);
			 T2f = VFNMS(LDK(KP250000000), T2e, T2d);
			 T25 = VSUB(T23, T24);
			 T28 = VSUB(T26, T27);
			 T29 = VBYI(VFMA(LDK(KP951056516), T25, VMUL(LDK(KP587785252), T28)));
			 T2i = VBYI(VFNMS(LDK(KP587785252), T25, VMUL(LDK(KP951056516), T28)));
			 ST(&(x[0]), VADD(T2d, T2e), ms, &(x[0]));
			 T2h = VSUB(T2f, T2c);
			 ST(&(x[WS(rs, 8)]), VSUB(T2h, T2i), ms, &(x[0]));
			 ST(&(x[WS(rs, 12)]), VADD(T2i, T2h), ms, &(x[0]));
			 T2g = VADD(T2c, T2f);
			 ST(&(x[WS(rs, 4)]), VADD(T29, T2g), ms, &(x[0]));
			 ST(&(x[WS(rs, 16)]), VSUB(T2g, T29), ms, &(x[0]));
		    }
		    {
			 V T1Z, T1X, T1Y, T1R, T22, T1J, T1Q, T21, T20;
			 T1Z = VMUL(LDK(KP559016994), VSUB(T1V, T1W));
			 T1X = VADD(T1V, T1W);
			 T1Y = VFNMS(LDK(KP250000000), T1X, T1U);
			 T1J = VSUB(T1F, T1I);
			 T1Q = VSUB(T1M, T1P);
			 T1R = VBYI(VFNMS(LDK(KP587785252), T1Q, VMUL(LDK(KP951056516), T1J)));
			 T22 = VBYI(VFMA(LDK(KP951056516), T1Q, VMUL(LDK(KP587785252), T1J)));
			 ST(&(x[WS(rs, 10)]), VADD(T1U, T1X), ms, &(x[0]));
			 T21 = VADD(T1Z, T1Y);
			 ST(&(x[WS(rs, 6)]), VSUB(T21, T22), ms, &(x[0]));
			 ST(&(x[WS(rs, 14)]), VADD(T22, T21), ms, &(x[0]));
			 T20 = VSUB(T1Y, T1Z);
			 ST(&(x[WS(rs, 2)]), VADD(T1R, T20), ms, &(x[0]));
			 ST(&(x[WS(rs, 18)]), VSUB(T20, T1R), ms, &(x[0]));
		    }
		    {
			 V T1k, T1r, T1z, T1w, T1o, T1y, T1h, T1v;
			 T1k = VFMA(LDK(KP951056516), T1i, VMUL(LDK(KP587785252), T1j));
			 T1r = VFMA(LDK(KP951056516), T1p, VMUL(LDK(KP587785252), T1q));
			 T1z = VFNMS(LDK(KP587785252), T1p, VMUL(LDK(KP951056516), T1q));
			 T1w = VFNMS(LDK(KP587785252), T1i, VMUL(LDK(KP951056516), T1j));
			 {
			      V T1m, T1n, T1f, T1g;
			      T1m = VFMS(LDK(KP250000000), T1d, TM);
			      T1n = VMUL(LDK(KP559016994), VSUB(T1c, TY));
			      T1o = VADD(T1m, T1n);
			      T1y = VSUB(T1n, T1m);
			      T1f = VMUL(LDK(KP559016994), VSUB(Tp, TE));
			      T1g = VFNMS(LDK(KP250000000), TF, T7);
			      T1h = VADD(T1f, T1g);
			      T1v = VSUB(T1g, T1f);
			 }
			 {
			      V T1l, T1s, T1B, T1C;
			      T1l = VADD(T1h, T1k);
			      T1s = VBYI(VSUB(T1o, T1r));
			      ST(&(x[WS(rs, 19)]), VSUB(T1l, T1s), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 1)]), VADD(T1l, T1s), ms, &(x[WS(rs, 1)]));
			      T1B = VADD(T1v, T1w);
			      T1C = VBYI(VADD(T1z, T1y));
			      ST(&(x[WS(rs, 13)]), VSUB(T1B, T1C), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 7)]), VADD(T1B, T1C), ms, &(x[WS(rs, 1)]));
			 }
			 {
			      V T1t, T1u, T1x, T1A;
			      T1t = VSUB(T1h, T1k);
			      T1u = VBYI(VADD(T1r, T1o));
			      ST(&(x[WS(rs, 11)]), VSUB(T1t, T1u), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 9)]), VADD(T1t, T1u), ms, &(x[WS(rs, 1)]));
			      T1x = VSUB(T1v, T1w);
			      T1A = VBYI(VSUB(T1y, T1z));
			      ST(&(x[WS(rs, 17)]), VSUB(T1x, T1A), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 3)]), VADD(T1x, T1A), ms, &(x[WS(rs, 1)]));
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 19),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 20, XSIMD_STRING("t3fv_20"), twinstr, &GENUS, {126, 80, 12, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_20) (planner *p) {
     X(kdft_dit_register) (p, t3fv_20, &desc);
}
#endif				/* HAVE_FMA */
