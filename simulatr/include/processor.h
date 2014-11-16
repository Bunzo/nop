#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Uint unsigned int
#define Uchar unsigned char

#define PENUM 1
#define GRNUM  8
#define PE(x) chip.p[x]

#include "clk.h"
#include "ia.h"
#include "if.h"
#include "mmem.h"

typedef struct {
	Uint reg;
} reg_s;

typedef struct {
	ia_s plia;
	if_s plif;

	reg_s gpr[GRNUM];
	mmem_s imem;
	mmem_s dmem;
} proc_s;

struct {
	clk_s clk;
	proc_s p[PENUM];
	mmem_s l2cache;
} chip;

void onintr();
#endif
