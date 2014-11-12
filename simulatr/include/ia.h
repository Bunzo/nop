#ifndef _IA_H_
#define _IA_H_

typedef struct {
	Uint pc:16;
} ia_s;

void program_counter(int, int);
#endif
