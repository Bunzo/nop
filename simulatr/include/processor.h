#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#define Uint unsigned int
#define Uchar unsigned char

#define PENUM 1

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "clk.h"
#include "ia.h"

typedef struct {
} proc_p;

struct {
	clk_s clk;
	proc_p p[PENUM];
} chip;


#endif
