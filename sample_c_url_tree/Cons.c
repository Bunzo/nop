#include <stdio.h>
#include <stdlib.h>

#include "Cons.h"

Cons* createCons(int n)
{
  Cons* c = (Cons*)malloc(sizeof(Cons));
  if (c == NULL)
    {
      fprintf(stderr, "cannot allocate Cons\n");
      return NULL;
    }
  c->car = n;
  c->cdr = NULL;
  return c;
}

void freeCons(Cons* c)
{
  free(c);
}

int car(Cons* c)
{
  return c->car;
}

Cons* cdr(Cons* c)
{
  return c->cdr;
}

Cons* append(Cons* a, Cons *b)
{
  //a->cdr = b;
  Cons* ptr;
  ptr = a;

  while (ptr->cdr != NULL)
    ptr = ptr->cdr;
  
  ptr->cdr = b;
  return a;
}

unsigned int length(Cons* c)
{
  unsigned int count = 0;
  Cons* ptr = c;
  while(cdr(ptr) != NULL)
    {
      count++;
      ptr = cdr(ptr);
    }
  return ++count;
}

void printCons(Cons* c)
{
  Cons* ptr;
  ptr = c;
  while (ptr != NULL)
    {
      printf("%d ", car(ptr));
      ptr = cdr(ptr);
    }
  printf("\n");
}

Cons* copyCons(Cons* c)
{
  Cons* ret = 0;
  while(c != NULL)
    {
      if (ret == NULL)
        ret = createCons(car(c));
      else
        ret = append(ret, createCons(car(c)));
      c = c->cdr;
    }
  return ret;
}

int elt(Cons* c, int index)
{
  while(index-- > 0)
    {
      c = c->cdr;
    }
  return c->car;
}
