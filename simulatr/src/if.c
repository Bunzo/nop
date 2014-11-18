#include "processor.h"

void if_init()
{
	int i, j;
	for (i=0; i<PENUM; i++) {
		for (j=0; j<IFQSIZE; j++) {
			PE(i).plif.ins[j] = 0x0;
		}

		PE(i).plif.full  = 0x0;
		PE(i).plif.empty = 0x0;
		PE(i).plif.top   = 0x0;
		PE(i).plif.bot   = 0x0;
	}
}

Uint if_full(Uint pid)
{
	return PE(pid).plif.top-1 == PE(pid).plif.bot;
}

Uint if_empty(Uint pid)
{
	return PE(pid).plif.top == PE(pid).plif.bot;
}

Uint if_ins(Uint pid)
{
	if (if_full(pid)) {
		return 1;
	}

	PE(pid).plif.ins[PE(pid).plif.bot] = PE(pid).imem.mem[PE(pid).plia.pc];
	return 0;
}
