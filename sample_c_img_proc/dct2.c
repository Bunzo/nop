//=============================================================================;
// file name   : convert.c
// last update : Jan 31 2010
// by Gen Oshiyama
//=============================================================================;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Image.h"
#include "Block.h"
//#include "psnr.h"
//#include "dct2.h"
//------------------------------------------------------------------------------;
static const double PI = 3.1416;
static const int N = 8;
//------------------------------------------------------------------------------;
double c(int i, int j)
{
    if (i==0 && j==0) return (double)1/2;
    if (i!=0 && j!=0) return (double)1;
    else return (double)1/sqrt(2);
}

double func_cos(int i, int m, int j, int n)
{
    return cos((2*m+1)*i*PI/(2*N))*cos((2*n+1)*j*PI/(2*N));
}
//------------------------------------------------------------------------------;
double** createVariance(const int b_num_x, const int b_num_y)
{
    double **var;
    int x, y;
    var = (double**)malloc(sizeof(double*)*b_num_y);
    if (var == NULL) {
	fprintf(stderr, "Cant allocate variance y");
	return NULL;
    }
    for (y=0; y<b_num_y; y++) {
	var[y] = (double*)malloc(sizeof(double)*b_num_x);
	if (var[y] == NULL) {
	    fprintf(stderr, "Cant allocate variance x");
	    return NULL;
	}
    }
    return var;
}
//------------------------------------------------------------------------------;
double** calcVarianceOfDCT2(Image input, const int opt)
{
    Block *block;         // structure block
    int b_num_x, b_num_y; // number of block
    double **var;         // variance
    int bx, by;           // block x,y
    int ex, ey;           // block element x,y (N*N)
    int m, n, i, x, y;
    int num;
    double tmp, tmp_ave, tmp_var;
    int cnt_block = 0;

    // check size
    b_num_x = input.x;
    b_num_y = input.y;
    if ((b_num_x % 8 == 0) && (b_num_y % 8 == 0))
    {
	fprintf(stderr, "file size error : Cant devide by 8");
	exit(1);
    }
    b_num_x = b_num_x/8;
    b_num_y = b_num_y/8;
    
    // allocate Block and **var
    block = createBlock(b_num_x, b_num_y);
#ifdef DEBUG
    printf("error in allocating block memoly \n");
#endif

    var = createVariance(b_num_x, b_num_y);
#ifdef DEBUG
    printf("error in allocating variance memoly \n");
#endif
    
    // do DCT in 2 dim
    for (by=0; by<b_num_y; by++) {
	for (bx=0; bx<b_num_x; bx++) {
	    block[cnt_block].hor_num = by;
	    block[cnt_block].ver_num = bx;
	    for (ey=0; ey<N; ey++) {
		for (ex=0; ex<N; ex++) {
		    tmp = 0.0;
		    for (m=0; m<N; m++) {
			for (n=0; n<N; n++) {
			    tmp += input.loc[m+ey*N][n+ex*N]*func_cos(ey,m, ex,n);
			}
		    }
		    tmp = 2*c(ey,ex)/N;
		    block[cnt_block].cell[ey][ex] = tmp;
		}
	    }
	    cnt_block++;
	}
    }
    
    // calc variance
    for (ey=0; ey<N; ey++) {      // loop_block_e
	for (ex=0; ex<N; ex++) {  // loop_block_e
	    // calc ave
	    tmp_ave = 0.0;
	    for (num=0; num<cnt_block; num++) {
		tmp_ave += block[num].cell[ey][ex];
	    }
	    tmp_ave = tmp_ave / cnt_block;
	    // calc var
	    tmp_var = 0.0;
	    for (num=0; num<cnt_block; num++) {
		tmp_var += pow((tmp_ave - block[num].cell[ey][ex]),2);
	    }
	    tmp_var = tmp_var / cnt_block;
	    var[ey][ex] = tmp_var;
	}
    }
    
    switch (opt) {
	case 1 :
	    for (i=0; i<3; i++)
            printf("block(%d,%d)\n", block[i].hor_num, block[i].hor_num);
	    for (y=0; y<N; y++) {      // loop block_element
            for (x=0; x<N; x++) {  // loop block_element
                printf("%d\t", (int)block[i].cell[y][x]);
            }
            printf("\n");
	    }
	    break;
	default :
	    break;
    }
    freeBlock(&block);
    return var;
}

