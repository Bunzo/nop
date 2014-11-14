//=============================================================================;
// file name   : psnr.c
// last update : Jan 23 2009
// by Gen Oshiyama
//=============================================================================;
#include <math.h>

#include "Image.h"

//------------------------------------------------------------------------------;
double calcPsnr(Image input, Image tmp)
{
    int size, x, y;
    double ans, sum, unko;
    
    sum = 0.0;
    size = input.x * input.y;
    if (size == 0) size = 1;
    for (y = 0; y < input.y; y++)
      for (x = 0; x < input.x; x++)
	  sum += pow((tmp.loc[y][x] - input.loc[y][x]), 2);
    unko = sum/(double)size;
    ans = 20 * log10(255/sqrt(unko));
    
    return ans;
}
//------------------------------------------------------------------------------;

