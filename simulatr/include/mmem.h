#ifndef _MMEM_H_
#define _MMEM_H_

typedef struct {
  Uchar *p;
} mmem_s;

Uchar* mmem_alloc(size_t s);
Uchar* mmem_read(Uint addr);
Uchar* mmem_write(Uint addr);

#endif
