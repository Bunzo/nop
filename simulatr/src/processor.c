#include "processor.h"

int main(int argc, char **argv)
{
	clk_rst();

	mmem_alloc(0, 100);
	mmem_write(&PE(0).imem, 0, 0xdeadbeef);
	printf("%x \n", mmem_read(&PE(0).imem, 0));
	printf("%p \n", mmem_base(&PE(0).imem));
	printf("%p \n", mmem_base(&PE(0).imem)+0x4);

	onintr();

	while (1) {
		if (clk_stat() == POSEDGE_CLK){
			pc_inc(0);
		}
		if (pc_pc(0) > 10) {
			break;
		}
		clk_clk();
		clk_showattr();
	}

	return 0;
}

void onintr()
{
	int i;
	for (i=0; i<PENUM; i++) {
		free(PE(i).imem.mem);
		free(PE(i).dmem.mem);
	}
	free(chip.l2cache.mem);

	exit(0);
}
