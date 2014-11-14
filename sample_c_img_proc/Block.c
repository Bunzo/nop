//=============================================================================;
// file name   : Block.h
// last update : Jan 23 2009
// by Gen Oshiyama
//=============================================================================;

#include <stdio.h>
#include <stdlib.h>

#include "Block.h"
//------------------------------------------------------------------------------;
Block* createBlock(const int x, const int y)
{
    Block *new;
    new = (Block*)malloc(sizeof(Block)*(x*y));
    if (new == NULL) {
        fprintf(stderr, "Cant allocate Block");
        return NULL;
    }
//    restoreValue();
    return new;
}
//------------------------------------------------------------------------------;
void freeBlock(Block* block)
{
    //    free(block->cell);
    //    free(block->hor_num);
    //    free(block->ver_num);
    //    free(block->x);
    //    free(block->y);
    free(block);
}
//------------------------------------------------------------------------------;
double** getCell(Block* block)
{
    return block->cell;
}
//------------------------------------------------------------------------------;
int getHorNum(Block* block)
{
    return block->hor_num;
}

int getVerNum(Block* block)
{
    return block->ver_num;
}
//------------------------------------------------------------------------------;
int getX(Block* block)
{
    return block->x;
}
int getY(Block* block)
{
    return block->y;
}
//--end-of-file-----------------------------------------------------------------;
