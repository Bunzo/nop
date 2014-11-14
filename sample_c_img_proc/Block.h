//=============================================================================;
// file name   : Block.h
// last update : Jan 23 2009
// by Gen Oshiyama
//=============================================================================;

#ifndef __IP_BLOCK_H_
#define __IP_BLOCK_H_

typedef struct _Block8
{
    double cell[8][8];
    int hor_num;
    int ver_num;
    int x, y;
} Block;

Block* createBlock(const int x, const int y);
void freeBlock(Block*);
double** getCell(Block*);
int getHorNum(Block*);
int getVerNum(Block*);
int getX(Block*);
int getY(Block*);

#endif // __IP_BLOCK_H_
