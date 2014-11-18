#ifndef _IF_H_
#define _IF_H_

#define IFQSIZE 4

typedef struct {
	Uint ins[IFQSIZE];
	Uint full: 1;
	Uint empty: 1;
	Uint top: 2;                  /* log(IFQSIZE) */
	Uint bot: 2;                  /* log(IFQSIZE) */
} if_s;

void if_init();
Uint if_ins(Uint);
Uint if_full(Uint);
Uint if_empty(Uint);

#endif
