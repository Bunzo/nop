#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Uint unsigned int
#define Uchar unsigned char

#define PENUM 1
#define GRNUM 8
#define STNUM 1
#define PE(x) chip.p[x]
#define ICACHESIZE 1<<10
#define DCACHESIZE 1<<10

#include "clk.h"
#include "ia.h"
#include "if.h"
#include "mmem.h"
#include "wb.h"

typedef struct {
	Uint reg: 32;
} gr_s;

typedef struct {
	ia_s plia;
	if_s plif;

	gr_s gpr[GRNUM];
	mmem_s imem;
	mmem_s dmem;

	wb_s plwb;
} proc_s;

struct {
	clk_s clk;
	proc_s p[PENUM];
	mmem_s l2cache;
} chip;

void onintr();
void pe_construction();
void pe_destruction();
#endif
