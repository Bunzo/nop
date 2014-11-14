#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Search.h"

typedef struct _ConsList
{
  Cons* cons;
  struct _ConsList* next;
} ConsList;


/* Cons* searchPath(Map map, int start, int end) */
/* { */
/*   Cons* result; */
/*   Cons* stack; */
/*   int currentPosition; */
/*   CheckMap cmap; */
/*   Cons* ptr; */
/*   Cons* pos_ptr; */
/*   Cons* path; */
/*   int next; */
/*   int count = 0; */
  
/*   path = createCons(start); */
/*   cmap = createCheckMap(getMapDimension(map)); */
/*   currentPosition = start; */
/*   stack = getCandidate(map, cmap, start); */
/*   stack = append(createCons(count), stack); */
/*   printCons(stack); */
/*   while (currentPosition != end) */
/*     { */
/*       //Œ»Ý‚Ìpos‚ðcheck */
/*       checkCheckMap(cmap, currentPosition); */
      
/*       ////////////////////////////////////////////////////////////////////////////////////////// */
/*       //move */
/*       //currentPosition = moveTo(stack, map, cmap, currentPosition); */
/*       ptr = stack; */
/*       //while (cmap[car(ptr)] != NOTPASSED || map[currentPosition][car(ptr)] == UNPASSABLE) */
/*       while (checkPath(path, currentPosition) != 1 || */
/*              map[currentPosition][car(ptr)] == UNPASSABLE || */
/*              ptr == NULL) */
/*         { */
/*           printf("%d -> %d missed\n", currentPosition, car(ptr)); */
/*           ptr = cdr(ptr); */
/*         } */
/*       //ptr == NULL -> too move */
/*       if (ptr == NULL) */
/*         { */
/*           int len = length(path); */
/*           int i; */
/*           pos_ptr = path; */
/*           for (i = 0; i < len - 1; i++) */
/*             pos_ptr = cdr(pos_ptr); */
/*           currentPosition = car(pos_ptr); */
/*           pos_ptr->cdr = NULL; */
/*           count--; */
/*           continue; */
/*         } */
      
/*       printf("goto %d -> %d\n", currentPosition, car(ptr)); */
/*       currentPosition = car(ptr); */
/*       checkCheckMap(cmap, car(ptr)); */
/*       stack = ptr; */
/*       path = append(createCons(currentPosition), path); */
/*       count++; */
/*       //                                                                                      // */
/*       ////////////////////////////////////////////////////////////////////////////////////////// */
      
/*       //stack = append(getCandidate(map, cmap, currentPosition), stack); */
/*       stack = append(stack, getCandidate(map, cmap, currentPosition)); */
/*       printCons(stack); */

/*     } */
/*   return NULL; */
/* } */


Cons* searchPath2(Map map, int start, int end)
{

  //initialize
  Cons* stack = 0;
  ConsList* first = 0;
  Cons* passed = 0;
  int currentPosition;
  int prev_stack_len;
  int extended_stack_len;

  first = (ConsList*)malloc(sizeof(ConsList));
  first->cons = createCons(start);
  first->next = NULL;
  
  currentPosition = start;
  passed = createCons(currentPosition);
  prev_stack_len = 0;
  stack = getCandidate(map, NULL, passed, start);
  
  extended_stack_len = length(stack) - prev_stack_len;
  if (extended_stack_len > 0)
    {
      int i;
      Cons* tmptmp;
      for (i = 0; i < extended_stack_len; i++)
        {
          tmptmp = copyCons(first->cons);
          tmptmp = append(tmptmp, createCons(elt(stack, prev_stack_len + i)));
          //ushiro ni tuika
          ConsList* j;
          for (j = first; j->next != NULL; j = j->next)
            ;
          j->next = (ConsList*)malloc(sizeof(ConsList));
          j = j->next;
          j->next = NULL;
          j->cons = tmptmp;
        }
    }
  //sentou wo sakuzyo
  //  first = first->next;
  
#ifdef DEBUG
  printf("%d extended\n", extended_stack_len);
  printf("stack is ");
  printCons(stack);
#endif
  
  printf("%d ->\n", currentPosition);
  
  //until goal
  while (currentPosition != end)
    {
      //first = first->next;
#ifdef DEBUG
      printf("first is ");
      printCons(first->cons);
#endif

      //push candidate
      prev_stack_len = length(stack);
      //stack = append(stack, getCandidate(map, stack, passed, currentPosition));
      stack = append(stack, getCandidate(map, stack, first->cons, currentPosition));
      extended_stack_len = length(stack) - prev_stack_len; 
  if (extended_stack_len > 0)
    {
      int i;
      Cons* tmptmp;
      for (i = 0; i < extended_stack_len; i++)
        {
          tmptmp = copyCons(first->cons);
          //tmptmp = append(createCons(elt(stack, prev_stack_len + i)), tmptmp);
          tmptmp =  append(tmptmp, createCons(elt(stack, prev_stack_len + i)));
          //ushiro ni tuika
          ConsList* j;
          for (j = first; j->next != NULL; j = j->next)
            ;
          j->next = (ConsList*)malloc(sizeof(ConsList));
          j = j->next;
          j->next = NULL;
          j->cons = tmptmp;
        }
    }
  //sentou wo sakuzyo
  first = first->next;
#ifdef DEBUG
      printf("%d extended\n", extended_stack_len);
      printf("stack is ");
      printCons(stack);
#endif
      currentPosition = car(stack);
      if (passed == NULL)
        passed = createCons(currentPosition);
      else
        passed = append(createCons(currentPosition), passed);
      printf("%d ->\n", currentPosition);
      stack = cdr(stack);
      
    }
  printf("shortest path is ");
  printCons(first->cons);
  printf("length is %d\n", length(first->cons) - 1);
  return NULL;
}
