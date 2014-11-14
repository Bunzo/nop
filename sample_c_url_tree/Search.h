#ifndef __SEARCH_H
#define __SEARCH_H

#include "Map.h"
#include "Cons.h"

Cons* searchPath(Map map, int start, int end);
Cons* searchPath2(Map map, int start, int end);
//int moveTo(Cons* stack, Map map, CheckMap cmap, int current);

#endif
