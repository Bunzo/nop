#ifndef _MMEM_H_
#define _MMEM_H_

typedef struct {
  Uint *mem;
} mmem_s;

void mmem_alloc(Uint, size_t);
Uint* mmem_base(mmem_s*);
Uint mmem_read(mmem_s*, Uint);
void mmem_write(mmem_s*, Uint, Uint);

#endif
