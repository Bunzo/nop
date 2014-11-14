#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "Cons.h"
#include "Map.h"
#include "Search.h"
//#include "Util.h"

void usage(void);

int main(int argc, char** argv)
{
  Node** nodes;
  Map map;
  int i, j;
  if (argc != 2)
    {
      printf("%s <URLfile>\n", *argv);
      exit(1);
    }
  
  printf("read URL from %s ...\n", *(argv + 1));
  
  nodes = readNodesFromFile(*(argv + 1));
#ifdef DEBUG
  printf("node length is %d\n", getNodesLength(nodes));
#endif
  
  map = readMapFromFile(*(argv + 1));
#ifdef DEBUG
  printf("map is \n");
  printMap(map);
#endif
  searchPath2(map, 0, 9);
  return 0;
}

