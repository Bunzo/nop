//=============================================================================;
// file name   : main.c
// last update : Jan 23 2009
// by Gen Oshiyama
//=============================================================================;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Image.h"
#include "Block.h"
//#include "psnr.h"
//#include "dct2.h"
//-----------------------------------------------------------------------------;
// psnr.c
extern double calcPsnr(Image input, Image tmp);
// dct2.c
extern double c(int i, int j);
extern double func_cos(int i, int m, int j, int n);
extern double** createVariance(const int b_num_x, const int b_num_y);
extern double** calcVarianceOfDCT2(Image input, const int opt);
// stereo.c
extern int calcLimit(int size);
extern double calcEnergy(Image left, Image right, int x, int y, int m, int n);
extern int calcDisparityLR(Image left, Image right, int x, int y);
extern Image getDispImg(Image img1, Image img2, Image dispImg);

//convert.c

//-----------------------------------------------------------------------------;
static const double PI = 3.1416;
static const int N = 8;
//-----------------------------------------------------------------------------;
void err()
{
    fprintf(stderr, "Please specify command\n");
    fprintf(stderr, "command option:\n");
    fprintf(stderr, "--psnr : calculate PSNR [input][tmp]\n");
    fprintf(stderr, "--varDCT2 : calculate variance of DCT2[input]\n");
    fprintf(stderr, "--varDCT2andPrint3Blocks[input]\n");
    fprintf(stderr, "--disp[input][tmp][output]\n");
    exit(1);
}
//------------------------------------------------------------------------------;
void main(int argc, char **argv)
{
    char option[64];                // command option
    int opt = 0;

    /**
     * command option
     * --psnr [InputFile][TmpFile] : calculate PSNR
     * --varDCT2 [InputFile]: calculate variance of DCT2
     * --varDCT2andP3B [input]
     * --disp[imput][tmp][output]
     */

    // apropos
    Image input, tmp, dispImg;    // structure Image
    double psnr;               // value of PSNR
    double **variance;         // variance of DCT2
    int x, y;
    
    // varify option
    strcpy(option, argv[1]);
    printf("%s\n", option);
    printf("%d\n", argc);
    if (strcmp(option,"--psnr")==0 && argc >= 4) opt = 1;
    else if (strcmp(option,"--varDCT2")==0 && argc >= 3) opt = 2;
    else if (strcmp(option,"--varDCT2andP3B")==0 && argc >= 3) opt = 3;
    else if (strcmp(option,"--disp")==0 && argc >= 5) opt = 4;
    else err();
    
    // function
    switch (opt) {
	// calc PSNR
	case 1:
	    loadImage(argv[2], &input);
	    loadImage(argv[3], &tmp);
	    psnr = calcPsnr(input, tmp);
	    printf("PSNR : %f\n", psnr);
	    break;
	// calc variace of DCT2
	case 2:
	    loadImage(argv[2], &input);
	    variance = calcVarianceOfDCT2(input, 0);
	    printf("Variance :\n");
	    for (y=0; y<N; y++) {      // loop_block
		for (x=0; x<N; x++) {  // loop_block
		    printf("%d\t", (int)variance[y][x]);
		}
		printf("\n");
	    }
	    free(variance);
	    break;
	// calc variance of DCT2 and print 3 Block
	case 3:
	    loadImage(argv[2], &input);
	    variance = calcVarianceOfDCT2(input, 1);
	    printf("Variance :\n");
	    for (y=0; y<N; y++) {      // loop_block
		for (x=0; x<N; x++) {  // loop_block
		    printf("%d\t", (int)variance[y][x]);
		}
		printf("\n");
	    }
	    free(&variance);
	    break;
	// disparity
	case 4:
	    loadImage(argv[2], &input);
	    loadImage(argv[3], &tmp);
	    newImageFromSizeOfImg(&tmp, &dispImg);
	    printf("disp!\n");
	    dispImg = getDispImg(input, tmp, dispImg);
	    saveImage (argv[4], &dispImg);
	    printf("done!\n");
	    free(&dispImg);
	    break;
	// error
	default:
	    err();
	    break;
    }
    
    // 画像用メモリの解放
    freeImage(&input);
    freeImage(&tmp);
    exit(1);
}

