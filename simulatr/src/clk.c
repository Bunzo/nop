#include "processor.h"

void clk_clk(void)
{
	chip.clk.prev_clk = chip.clk.clk;
	chip.clk.clk++;
	if (clk_stat() == POSEDGE_CLK) {
		chip.clk.counter++;
	}
}

void clk_showattr()
{
	printf("clk: %d, prev_clk: %d, cycle counter: %d \n", 
			chip.clk.clk, chip.clk.prev_clk, chip.clk.counter);
}

void clk_rst(void)
{
	printf("clk_rst\n");
	clk_showattr();
	chip.clk.clk = 0;
	chip.clk.prev_clk = 1;
	chip.clk.counter = 0;
}

Uint clk_stat()
{
	if (chip.clk.clk == 0x1 && chip.clk.prev_clk == 0x0) {
		return POSEDGE_CLK;
	}	else if (chip.clk.clk == 0x0 && chip.clk.prev_clk == 0x1) {
		return NEGEDGE_CLK;
	}	else if (chip.clk.clk == 0x1 && chip.clk.prev_clk == 0x1) {
		return CLKSTOP_POS;
	}	else if (chip.clk.clk == 0x0 && chip.clk.prev_clk == 0x0) {
		return CLKSTOP_NEG;
	}

	return -1;
}
