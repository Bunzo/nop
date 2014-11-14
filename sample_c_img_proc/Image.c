/*****************************************************************************/
/*          FILE NAME        Image.c                                         */
/*          AUTHOR           Gen                                             */
/*          RELEASED AT      Dec 11, 2008                                    */
/*****************************************************************************/
/*          Class            struct Image                                    */
/*          Method           manage Image                                    */
/*****************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Image.h"

/* =============================================================== */
/* read Integer data */
int getInt(FILE *fp)
{
    int c, i, top;
    
    c = getc(fp);
    while (1) {
	if (c == '#'){   // #
	    top = 1;     // top=1
	    while (1) {
		c = getc(fp);
		if (top && c == ' ') top = 0; // # && %s = top0
		else if (c == '\n' || c == EOF) break; // \n
	    }
	}
	if (c == EOF) return(0);
	if (c >= '0' && c <= '9') break;
	c = getc(fp);
    }
    
    i = 0;
    while (1) {
	i = (i*10) + (c - '0');
	c = getc(fp);
	if (c == EOF) return(i);
	if (c < '0' || c > '9') break;
    }
    
    return(i);
}

/* =============================================================== */
/* allocate Image memory */
void mallocImage(Image* img)
{
    int y, size;
    unsigned char *tmp;
    // Image img;

    size = img->x * img->y;

    if(!(img->buf=(unsigned char  *)malloc(sizeof(char  )*size))){
        printf("Cannot allocate memory !\n");
        exit(1);
    }
    if(!(img->loc = (unsigned char **)malloc(sizeof(char *) * img->y))){
        printf("Cannot allocate memory !!\n");
        exit(1);
    }
    tmp = img->buf;

    for(y = 0; y < img->y; y++){
        img->loc[y] = tmp;
        tmp += img->x;
    }
}

/* =============================================================== */
/* load Image */
void loadImage(char* fname, Image* img)
{
    FILE *fp;
    int   c1, c2, size;

    if(!(fp = fopen(fname, "rb"))){
        fprintf(stderr, "Cannot Find Input File(%s)\n", fname);
        exit(1);
    }

    c1 = getc(fp);  c2 = getc(fp);
    if (c1!='P' || c2!='5'){
        fprintf(stderr, "PGM Format Error i\n");
        exit(1);
    }

    img->x = getInt(fp);
    img->y = getInt(fp);
    size = (img->x)*(img->y);

    if((c1 = getInt(fp)) != 255){
        fprintf(stderr, "PGM Format Error s\n");
        exit(1);
    }

    mallocImage(img);
#ifdef DEBUG
    fprintf(stdrr, "Cant allocate Image Error\n");
#endif

    if(!(fread(img->buf, sizeof(char), size, fp))){
        fprintf(stderr, "File read Error in Image Loader\n");
        exit(1);
    }

//    printf("%s is loaded.\n", fname);
    fclose(fp);
}

/* =============================================================== */
/* load PGM Image */
void loadImagePGM(char* fname, Image* img)
{
    FILE *fp;
    int   c1, c2, size;
    char *flag;

    if (!(fp = fopen(fname, "rb"))){
        fprintf(stderr, "Cannot Find Input File(%s)\n", fname);
        exit(1);
    }

    c1 = getc(fp);
    c2 = getc(fp);
    
    if (c1=='P' && c2=='5') *flag = "PGM_BINARY";
    if (c1=='P' && c2=='2') *flag = "PGM_ASCII";

    if (flag == NULL) {
        fprintf(stderr, "PGM Format Error i\n");
        exit(1);
    }

    img->x = getInt(fp);
    img->y = getInt(fp);
    size = (img->x)*(img->y);

    if((c1 = getInt(fp)) != 255){
        fprintf(stderr, "PGM Format Error s\n");
        exit(1);
    }

    mallocImage(img);
#ifdef DEBUG
    fprintf(stdrr, "Cant allocate Image Error\n");
#endif

    if(!(fread(img->buf, sizeof(char), size, fp))){
        fprintf(stderr, "File read Error in Image Loader\n");
        exit(1);
    }

//    printf("%s is loaded.\n", fname);
    fclose(fp);
}

/* =============================================================== */
/* create Image from size */
void newImageFromSize(int x, int y, Image* tmp)
{
    tmp->x = x;
    tmp->y = y;
    mallocImage(tmp);
}

/* =============================================================== */
/* create Image */
void newImageFromSizeOfImg(Image* img, Image* tmp)
{
    tmp->x = img->x;
    tmp->y = img->y;
    mallocImage(tmp);
}

/* =============================================================== */
/* export Image */
void saveImage(char* fname, Image* img)
{
    FILE *fp;
    int size;
    
    size = img->x * img->y;
    
    if(!(fp = fopen(fname, "wb"))){
	printf("Cannot Make Output File(%s)!\n", fname);
    }
    
    fprintf(fp, "P5\n%d %d\n255\n", img->x, img->y);
    
    if(!(fwrite(img->buf, sizeof(char), size, fp))){
	printf("Fwrite Error\n");
    }
    
    printf("%s is saved.\n", fname);
    fclose(fp);
}

/* =============================================================== */
/* free Image */
void freeImage(Image* img)
{
    free(img->buf);
    free(img->loc);
}

/* =============================================================== */
/* get Max Bright pixel value from image */
unsigned char getMaxValue(Image* img)
{
    int x, y;
    unsigned char value, max = 0;
    for (y = 0; y < img->y; y++) {
        for (x = 0; x < img->x; x++) {
            value = img->loc[y][x];
            if (max < value) max = value;
        }
    }
    return max;
}

//-----------------------------------------------------------------------------;

