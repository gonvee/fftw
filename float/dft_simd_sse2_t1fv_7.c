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
/* Generated on Sun Nov 25 07:38:01 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 7 -name t1fv_7 -include t1f.h */

/*
 * This function contains 36 FP additions, 36 FP multiplications,
 * (or, 15 additions, 15 multiplications, 21 fused multiply/add),
 * 42 stack variables, 6 constants, and 14 memory accesses
 */
#include "t1f.h"

static void t1fv_7(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 12)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 12), MAKE_VOLATILE_STRIDE(7, rs)) {
	       V T1, T2, T4, Te, Tc, T9, T7;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
	       Te = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
	       Tc = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
	       T9 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
	       T7 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
	       {
		    V T3, T5, Tf, Td, Ta, T8;
		    T3 = BYTWJ(&(W[0]), T2);
		    T5 = BYTWJ(&(W[TWVL * 10]), T4);
		    Tf = BYTWJ(&(W[TWVL * 6]), Te);
		    Td = BYTWJ(&(W[TWVL * 4]), Tc);
		    Ta = BYTWJ(&(W[TWVL * 8]), T9);
		    T8 = BYTWJ(&(W[TWVL * 2]), T7);
		    {
			 V T6, Tk, Tg, Tl, Tb, Tm;
			 T6 = VADD(T3, T5);
			 Tk = VSUB(T5, T3);
			 Tg = VADD(Td, Tf);
			 Tl = VSUB(Tf, Td);
			 Tb = VADD(T8, Ta);
			 Tm = VSUB(Ta, T8);
			 {
			      V Th, Ts, Tp, Tu, Tn, Tx, Ti, Tt;
			      Th = VFNMS(LDK(KP356895867), T6, Tg);
			      Ts = VFMA(LDK(KP554958132), Tl, Tk);
			      ST(&(x[0]), VADD(T1, VADD(T6, VADD(Tb, Tg))), ms, &(x[0]));
			      Tp = VFNMS(LDK(KP356895867), Tb, T6);
			      Tu = VFNMS(LDK(KP356895867), Tg, Tb);
			      Tn = VFMA(LDK(KP554958132), Tm, Tl);
			      Tx = VFNMS(LDK(KP554958132), Tk, Tm);
			      Ti = VFNMS(LDK(KP692021471), Th, Tb);
			      Tt = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), Ts, Tm));
			      {
				   V Tq, Tv, To, Ty, Tj, Tr, Tw;
				   Tq = VFNMS(LDK(KP692021471), Tp, Tg);
				   Tv = VFNMS(LDK(KP692021471), Tu, T6);
				   To = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tn, Tk));
				   Ty = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tx, Tl));
				   Tj = VFNMS(LDK(KP900968867), Ti, T1);
				   Tr = VFNMS(LDK(KP900968867), Tq, T1);
				   Tw = VFNMS(LDK(KP900968867), Tv, T1);
				   ST(&(x[WS(rs, 2)]), VFMAI(To, Tj), ms, &(x[0]));
				   ST(&(x[WS(rs, 5)]), VFNMSI(To, Tj), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 1)]), VFMAI(Tt, Tr), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 6)]), VFNMSI(Tt, Tr), ms, &(x[0]));
				   ST(&(x[WS(rs, 3)]), VFMAI(Ty, Tw), ms, &(x[WS(rs, 1)]));
				   ST(&(x[WS(rs, 4)]), VFNMSI(Ty, Tw), ms, &(x[0]));
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 7, XSIMD_STRING("t1fv_7"), twinstr, &GENUS, {15, 15, 21, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_7) (planner *p) {
     X(kdft_dit_register) (p, t1fv_7, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 7 -name t1fv_7 -include t1f.h */

/*
 * This function contains 36 FP additions, 30 FP multiplications,
 * (or, 24 additions, 18 multiplications, 12 fused multiply/add),
 * 21 stack variables, 6 constants, and 14 memory accesses
 */
#include "t1f.h"

static void t1fv_7(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 12)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 12), MAKE_VOLATILE_STRIDE(7, rs)) {
	       V T1, Tg, Tj, T6, Ti, Tb, Tk, Tp, To;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       {
		    V Td, Tf, Tc, Te;
		    Tc = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    Td = BYTWJ(&(W[TWVL * 4]), Tc);
		    Te = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tf = BYTWJ(&(W[TWVL * 6]), Te);
		    Tg = VADD(Td, Tf);
		    Tj = VSUB(Tf, Td);
	       }
	       {
		    V T3, T5, T2, T4;
		    T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTWJ(&(W[0]), T2);
		    T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    T5 = BYTWJ(&(W[TWVL * 10]), T4);
		    T6 = VADD(T3, T5);
		    Ti = VSUB(T5, T3);
	       }
	       {
		    V T8, Ta, T7, T9;
		    T7 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    T8 = BYTWJ(&(W[TWVL * 2]), T7);
		    T9 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Ta = BYTWJ(&(W[TWVL * 8]), T9);
		    Tb = VADD(T8, Ta);
		    Tk = VSUB(Ta, T8);
	       }
	       ST(&(x[0]), VADD(T1, VADD(T6, VADD(Tb, Tg))), ms, &(x[0]));
	       Tp = VBYI(VFMA(LDK(KP433883739), Ti, VFNMS(LDK(KP781831482), Tk, VMUL(LDK(KP974927912), Tj))));
	       To = VFMA(LDK(KP623489801), Tb, VFNMS(LDK(KP222520933), Tg, VFNMS(LDK(KP900968867), T6, T1)));
	       ST(&(x[WS(rs, 4)]), VSUB(To, Tp), ms, &(x[0]));
	       ST(&(x[WS(rs, 3)]), VADD(To, Tp), ms, &(x[WS(rs, 1)]));
	       {
		    V Tl, Th, Tn, Tm;
		    Tl = VBYI(VFNMS(LDK(KP781831482), Tj, VFNMS(LDK(KP433883739), Tk, VMUL(LDK(KP974927912), Ti))));
		    Th = VFMA(LDK(KP623489801), Tg, VFNMS(LDK(KP900968867), Tb, VFNMS(LDK(KP222520933), T6, T1)));
		    ST(&(x[WS(rs, 5)]), VSUB(Th, Tl), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 2)]), VADD(Th, Tl), ms, &(x[0]));
		    Tn = VBYI(VFMA(LDK(KP781831482), Ti, VFMA(LDK(KP974927912), Tk, VMUL(LDK(KP433883739), Tj))));
		    Tm = VFMA(LDK(KP623489801), T6, VFNMS(LDK(KP900968867), Tg, VFNMS(LDK(KP222520933), Tb, T1)));
		    ST(&(x[WS(rs, 6)]), VSUB(Tm, Tn), ms, &(x[0]));
		    ST(&(x[WS(rs, 1)]), VADD(Tm, Tn), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 7, XSIMD_STRING("t1fv_7"), twinstr, &GENUS, {24, 18, 12, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_7) (planner *p) {
     X(kdft_dit_register) (p, t1fv_7, &desc);
}
#endif				/* HAVE_FMA */
