#include "processor.h"

void wb_write_back(Uint pid, wbpr_s* r)
{
	r->reg = PE(pid).plwb.pr.reg;
}

