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
/* Generated on Sun Nov 25 07:36:52 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 5 -name n1fv_5 -include n1f.h */

/*
 * This function contains 16 FP additions, 11 FP multiplications,
 * (or, 7 additions, 2 multiplications, 9 fused multiply/add),
 * 23 stack variables, 4 constants, and 10 memory accesses
 */
#include "n1f.h"

static void n1fv_5(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(10, is), MAKE_VOLATILE_STRIDE(10, os)) {
	       V T1, T2, T3, T5, T6;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T3 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       T5 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T6 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       {
		    V Tc, T4, Td, T7;
		    Tc = VSUB(T2, T3);
		    T4 = VADD(T2, T3);
		    Td = VSUB(T5, T6);
		    T7 = VADD(T5, T6);
		    {
			 V Tg, Te, Ta, T8, T9, Tf, Tb;
			 Tg = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), Tc, Td));
			 Te = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), Td, Tc));
			 Ta = VSUB(T4, T7);
			 T8 = VADD(T4, T7);
			 T9 = VFNMS(LDK(KP250000000), T8, T1);
			 ST(&(xo[0]), VADD(T1, T8), ovs, &(xo[0]));
			 Tf = VFNMS(LDK(KP559016994), Ta, T9);
			 Tb = VFMA(LDK(KP559016994), Ta, T9);
			 ST(&(xo[WS(os, 2)]), VFMAI(Tg, Tf), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 3)]), VFNMSI(Tg, Tf), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 4)]), VFMAI(Te, Tb), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 1)]), VFNMSI(Te, Tb), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 5, XSIMD_STRING("n1fv_5"), {7, 2, 9, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_5) (planner *p) {
     X(kdft_register) (p, n1fv_5, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 5 -name n1fv_5 -include n1f.h */

/*
 * This function contains 16 FP additions, 6 FP multiplications,
 * (or, 13 additions, 3 multiplications, 3 fused multiply/add),
 * 18 stack variables, 4 constants, and 10 memory accesses
 */
#include "n1f.h"

static void n1fv_5(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(10, is), MAKE_VOLATILE_STRIDE(10, os)) {
	       V T8, T7, Td, T9, Tc;
	       T8 = LD(&(xi[0]), ivs, &(xi[0]));
	       {
		    V T1, T2, T3, T4, T5, T6;
		    T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T3 = VADD(T1, T2);
		    T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T6 = VADD(T4, T5);
		    T7 = VMUL(LDK(KP559016994), VSUB(T3, T6));
		    Td = VSUB(T4, T5);
		    T9 = VADD(T3, T6);
		    Tc = VSUB(T1, T2);
	       }
	       ST(&(xo[0]), VADD(T8, T9), ovs, &(xo[0]));
	       {
		    V Te, Tf, Tb, Tg, Ta;
		    Te = VBYI(VFMA(LDK(KP951056516), Tc, VMUL(LDK(KP587785252), Td)));
		    Tf = VBYI(VFNMS(LDK(KP587785252), Tc, VMUL(LDK(KP951056516), Td)));
		    Ta = VFNMS(LDK(KP250000000), T9, T8);
		    Tb = VADD(T7, Ta);
		    Tg = VSUB(Ta, T7);
		    ST(&(xo[WS(os, 1)]), VSUB(Tb, Te), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VSUB(Tg, Tf), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 4)]), VADD(Te, Tb), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 2)]), VADD(Tf, Tg), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 5, XSIMD_STRING("n1fv_5"), {13, 3, 3, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_5) (planner *p) {
     X(kdft_register) (p, n1fv_5, &desc);
}

#endif				/* HAVE_FMA */
