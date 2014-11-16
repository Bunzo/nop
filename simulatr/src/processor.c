#include "processor.h"

int main(int argc, char **argv)
{
	clk_rst();
	pe_construction();

	while (1) {
		if (clk_stat() == POSEDGE_CLK){
			pc_inc(0);
		}
		if (pc_pc(0) > 1) {
			break;
		}
		mmem_write(&PE(0).imem, pc_pc(0), 0xdeadbeef);
		printf("D: %x \n", mmem_read(&PE(0).imem, pc_pc(0)));
		clk_clk();
#ifdef DEBUG
		clk_showattr();
#endif
	}

	onintr();
	return 0;
}

void onintr()
{
	pe_destruction();
	exit(0);
}

void pe_construction()
{
	int i;
	for (i=0; i<PENUM; i++) {
		mmem_alloc(&PE(i).imem, ICACHESIZE);
		mmem_alloc(&PE(i).dmem, DCACHESIZE);
	}
}

void pe_destruction()
{
	int i;
	for (i=0; i<PENUM; i++) {
		free(PE(i).imem.mem);
		free(PE(i).dmem.mem);
	}
	free(chip.l2cache.mem);
}

