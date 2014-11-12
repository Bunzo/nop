#ifndef _CLK_H_
#define _CLK_H_

#define POSEDGE_CLK 0
#define NEGEDGE_CLK 1
#define CLKSTOP_POS 2
#define CLKSTOP_NEG 3

typedef struct {
	Uint clk: 1;
	Uint prev_clk: 1;
	Uint counter: 32;
} clk_s;

void clk_clk ();
void clk_rst ();
void clk_showattr();

#endif
