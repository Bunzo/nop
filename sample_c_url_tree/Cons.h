#ifndef __CONS_H
#define __CONS_H

typedef struct _Cons
{
  int car;
  struct _Cons* cdr;
} Cons;

Cons* createCons(int);
void freeCons(Cons*);
int car(Cons*);
Cons* cdr(Cons*);
Cons* append(Cons*, Cons*);
unsigned int length(Cons*);
void printCons(Cons*);
Cons* copyCons(Cons*);
int elt(Cons*, int);
#endif //__CONS_H
