#ifndef _WB_H_
#define _WB_H_

typedef struct {
	Uint reg: 32;
} wbpr_s;
 
typedef struct {
	wbpr_s pr;
} wb_s;

void wb_write_back(Uint, wbpr_s*);

#endif
