#include "processor.h"

void clk_clk(void)
{
	chip.clk.prev_clk = chip.clk.clk;
	chip.clk.clk++;
	chip.clk.counter++;
}

void clk_showattr()
{
	printf("clk: %d, prev_clk: %d \n", chip.clk.clk, chip.clk.prev_clk);
}

void clk_rst(void)
{
	printf("clk_rst\n");
	clk_showattr();
	chip.clk.clk = 1;
	chip.clk.prev_clk = 0;
	chip.clk.counter = 0;
}
