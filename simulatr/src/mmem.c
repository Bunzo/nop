#include "processor.h"

void mmem_alloc(Uint pid, size_t s)
{
	if ( ! (PE(pid).imem.mem = (Uint *)malloc(s))) {
		perror(__FUNCTION__);
		onintr();
	}
}

Uint mmem_read(mmem_s* m, Uint addr)
{
	return m->mem[addr];
}

void mmem_write(mmem_s* m, Uint addr, Uint data)
{
	m->mem[addr] = data;
}

Uint* mmem_base(mmem_s *m)
{
	return m->mem;
}
