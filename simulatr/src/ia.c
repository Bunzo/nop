#include "processor.h"

void pc_inc(Uint pid)
{
  chip.p[pid].plia.pc += 0x4;
}

Uint pc_pc(Uint pid)
{
  return chip.p[pid].plia.base + chip.p[pid].plia.pc;
}
