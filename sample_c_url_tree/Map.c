#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Map.h"

#define LINE_MAX 512

Map createMap(unsigned int num)
{
  Map map;
  unsigned int i, j;
  map = (unsigned char**)malloc((num + 1) * sizeof(unsigned char*));
  if (map == NULL)
    {
      fprintf(stderr, "cannot allocate map\n");
      return NULL;
    }
  
  for (i = 0; i < num; i++)
    {
      map[i] = (unsigned char*)malloc(num * sizeof(unsigned char));
      if (map[i] == NULL)
	{
	  fprintf(stderr, "cannot allocate map\n");
	  for (j = i - 1; j > 0; j--)
	    free(map[j]);
	  free(map);
	  return NULL;
	}
      else
	for (j = 0; j < num; j++)
	  map[i][j] = 0;
    }
  
  *(map + num) = NULL;
  return map;
}

unsigned int getMapDimension(Map map)
{
  unsigned int i = 0;
  while (*map++ != NULL)
    i++;
  return i;
}

unsigned int getCheckMapDimension(CheckMap map)
{
  unsigned int i = 0;
  while (map++ != NULL)
    i++;
  return i;
}

/* Cons* getCandidate(Map map, CheckMap cmap, unsigned int index) */
/* { */
/*   int dim = getMapDimension(map); */
/*   Cons* cons = 0; */
/*   int i; */
/*   if (index > dim) */
/*     { */
/*       fprintf(stderr, "range over\n"); */
/*       return NULL; */
/*     } */
/*   for (i = 0; i < dim; i++) */
/*     if (i != index) */
/*       { */
/*         if (map[index][i] == PASSABLE && cmap[i] == NOTPASSED) */
/*           { */
/*             if (cons == NULL) */
/*               cons = createCons(i); */
/*             else */
/*               append(cons, createCons(i)); */
/*           } */
/*       } */
/*   return cons; */
/* } */

int checkPath(Cons* path, int target)
{
  int dim = length(path);
  int i;
  for (i = 0; i < dim; i++)
    {
#ifdef DEBUG
      printf("target %d car(path) is %d\n", target, car(path));
#endif
      if (car(path) == target)
        return 0;
      path = cdr(path);
    }
  return 1;
}

/* Cons* getCandidate(Map map, Cons* stack, unsigned int index) */
/* { */
/*   printf("getCandidate::stack is "); */
/*   printCons(stack); */

/*   int dim = getMapDimension(map); */
/*   Cons* cons = 0; */
/*   int i; */
/*   if (index > dim) */
/*     { */
/*       fprintf(stderr, "range over\n"); */
/*       return NULL; */
/*     } */
/*   for (i = 0; i < dim; i++) */
/*     if (i != index) */
/*       { */
/*         if (stack != NULL) */
/*           { */
/*             if (map[index][i] == PASSABLE && checkPath(stack, i)) */
/*               { */
/*                 if (cons == NULL) */
/*                   cons = createCons(i); */
/*                 else */
/*                   append(cons, createCons(i)); */
/*               } */
/*           } */
/*         else */
/*           { */
/*             if (map[index][i] == PASSABLE) */
/*               { */
/*                 if (cons == NULL) */
/*                   cons = createCons(i); */
/*                 else */
/*                   append(cons, createCons(i)); */
/*               } */
/*           } */
/*       } */
/*   return cons; */
/* } */

Cons* getCandidate(Map map, Cons* stack, Cons* passed, unsigned int index)
{
#ifdef DEBUG
  printf("getCandidate::stack is ");
  printCons(stack);
#endif
  int dim = getMapDimension(map);
  Cons* cons = 0;
  int i;
  if (index > dim)
    {
      fprintf(stderr, "range over\n");
      return NULL;
    }
  for (i = 0; i < dim; i++)
    if (i != index)
      {
        if (stack != NULL)
          {
            if (map[index][i] == PASSABLE && checkPath(stack, i) && checkPath(passed, i))
              //if (map[index][i] == PASSABLE && checkPath(stack, i))
              {
                if (cons == NULL)
                  cons = createCons(i);
                else
                  append(cons, createCons(i));
              }
          }
        else
          {
             if (map[index][i] == PASSABLE && checkPath(passed, i))
               //if (map[index][i] == PASSABLE)
              {
                if (cons == NULL)
                  cons = createCons(i);
                else
                  append(cons, createCons(i));
              }
          }
      }
  return cons;
}

Map readMapFromFile(char* fname)
{
  Map map;
  char line[LINE_MAX];
  char url[LINE_MAX];
  char name[LINE_MAX];
  int index;
  FILE* fp;
  int num;
  int count = 0;
  int from, to;
  
  fp = fopen(fname, "r");
  if (fp == NULL)
    {
      fprintf(stderr, "cannot open %s\n", fname);
      return NULL;
    }

  do
    {
      if (fgets(line, LINE_MAX, fp) == NULL)
	{
	  fprintf(stderr, "unexpected EOF\n");
	  return NULL;
	}
    }
  while(sscanf(line, "%d", &num) != 1);
  
  map = createMap(num);

  count = 0;
  while(count < num)
    {
      if(fgets(line, LINE_MAX, fp) == NULL)
	{
	  return NULL;
	}
      
      if(sscanf(line, "%d %s \"%[^\"]", &index, url, name) == 3)
	{
	  count++;
	}
    }

  count = 0;
  do
    {
      if (fgets(line, LINE_MAX, fp) == NULL)
	{
	  fprintf(stderr, "unexpected EOF\n");
	  return NULL;
	}
    }
  while(sscanf(line, "%d", &num) != 1);
  
  count = 0;
  while (count < num)
    {
      if (fgets(line, LINE_MAX, fp) == NULL)
	{
	  return NULL;
	}
      
      if(sscanf(line, "%d %d", &from, &to) == 2)
	{
	  map[from][to] = PASSABLE;
	  count++;
	}
    }
  return map;
}

void checkCheckMap(CheckMap cmap, unsigned int pos)
{
  cmap[pos] = PASSED;
}

CheckMap createCheckMap(unsigned int dim)
{
  return (unsigned char*)malloc(sizeof(unsigned char) * dim);
}

void printMap(Map map)
{
  int dim = getMapDimension(map);
  int i, j;
  for (i = 0; i < dim; i++)
    {
      for (j = 0; j < dim; j++)
        printf("%d ", map[i][j]);
      printf("\n");
    }
}

CheckMap copyCheckMap(CheckMap cmap)
{
  int i;
  int dim = getCheckMapDimension(cmap);
  CheckMap ret = createCheckMap(dim);
  for (i = 0; i < dim; ++i)
    ret[i] = cmap[i];
  return ret;
}
