//=============================================================================;
// file name   : stereo.c
// last update : Jan 23 2009
// by Gen Oshiyama
//=============================================================================;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Image.h"

//-----------------------------------------------------------------------------;
static const double PI = 3.1416;
static const int N = 8;
static const int X = 128;
static const int Y = 0;
static const int HOR = 5;
static const int VER = 3;

//-----------------------------------------------------------------------------;
int min(const int a, const int b)
{
    int ans = 100;
    if (a>b) ans = b;
    if (a<b) ans = a;
    else ans = a;
    return ans;
}

//-----------------------------------------------------------------------------;
int max(const int a, const int b)
{
    int ans = 0;
    if (a>b) ans = a;
    if (a<b) ans = b;
    else ans = a;
    return ans;
}

//-----------------------------------------------------------------------------;
double calcEnergy(Image base, Image comp, int x, int y, int m, int n)
{
    int i, j, cx, cy, bx, by;
    int num = 0;
    double energy, e = 0;
    for (i = -HOR; i <= HOR; i++) {
	for (j = -VER; j <= VER; j++) {
	    cx = x+n+i; bx = x+i;
	    cy = y+m+i; by = y+j;
	    if (!(min(cy,by)<0) && !(min(cx,bx)<0)
		 && max(cx,bx)>comp.x && max(cy,by)>comp.y) {
		e += abs((double)comp.loc[cy][cx] - (double)base.loc[by][bx]);
		num++;
	    }
	}
    }
    if (num == 0) num = 1;
    energy = e/num;
    return energy;
}
//-----------------------------------------------------------------------------;
int calcDisparityLR(Image left, Image right, int x, int y)
{
    int disp = 0;
    double e, energy = 9999.9;
    int m, n, test = 0;
    for (m = -Y; m <= Y; m++) {
	for (n = -X; n < 0; n++) {
		test++;
	    if (!(min(y,y+m)<0) && !(min(x,x+n)<0) && x<left.x && y<left.y) {
		e = calcEnergy(left, right, x, y, m, n);
		if (energy >= e && disp>n) {
		    energy = e;
		    disp = n;
		}
	    }
	}
    }
    printf("%d\n", test);
    return disp;
}

//-----------------------------------------------------------------------------;
Image getDispImg(Image img1, Image img2, Image dispImg)
{
    int x, y;
    printf("img1.x=%d\n", img1.x);
    printf("img1.y=%d\n", img1.y);
    printf("img2.x=%d\n", img2.x);
    printf("img2.y=%d\n", img2.y);
    printf("disp.x=%d\n", dispImg.x);
    printf("disp.y=%d\n", dispImg.y);
    dispImg.x = img1.x;
    dispImg.y = img1.y;
    printf("disp1\n");
    for (y = 0; y < img1.y; y++) {
	for (x = 0; x <img1.x; x++) {
	    dispImg.loc[y][x] = calcDisparityLR(img1, img2, x, y);
	}
    }
    printf("disp4\n");
    for (y = 0; y < img1.y; y++) {
	for (x = 0; x < img1.x; x++) {
	    dispImg.loc[y][x] = 255*dispImg.loc[y][x]/getMaxValue(&dispImg);
	}
    }
    printf("disp5\n");
    return dispImg;
}

//-----------------------------------------------------------------------------;

