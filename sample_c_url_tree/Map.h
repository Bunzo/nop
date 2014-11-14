#ifndef __MAP_H
#define __MAP_H

#include "Node.h"
#include "Cons.h"

enum {UNPASSABLE = 0, PASSABLE};
enum {NOTPASSED = 0, PASSED};
typedef unsigned char** Map;
typedef unsigned char* CheckMap;

Map createMap(unsigned int num);
unsigned int getMapDimension(Map map);
unsigned int getCheckMapDimension(CheckMap map);
//Cons* getCandidate(Map map, CheckMap cmap, unsigned int index);
//Cons* getCandidate(Map map, Cons* stack, unsigned int index);
Cons* getCandidate(Map map, Cons* stack, Cons* passed, unsigned int index);
Map readMapFromFile(char*);
int checkPath(Cons* path, int target);
CheckMap createCheckMap(unsigned int dim);
void checkCheckMap(CheckMap cmap, unsigned int pos);
void printMap(Map map);
CheckMap copyCheckMap(CheckMap cmap);
#endif //__MAP_H
