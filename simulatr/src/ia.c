#include "processor.h"

void pc_inc(Uint pid)
{
	PE(pid).plia.pc += 0x4;
#ifdef DEBUG
	fprintf(stdout, "pid: %d pc: %d \n", pid, PE(pid).plia.pc);
#endif

}

Uint pc_pc(Uint pid)
{
#ifdef DEBUG
	fprintf(stdout, "pid: %d pc: %d \n", pid, PE(pid).plia.pc);
#endif
	return PE(pid).plia.base + PE(pid).plia.pc;
}
