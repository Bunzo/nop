#ifndef _IA_H_
#define _IA_H_

typedef struct {
	Uint pc;
  Uint base;
} ia_s;

void pc_inc(Uint);              /* Increment the PC */
Uint pc_pc(Uint);               /* return the PC's value */
#endif
