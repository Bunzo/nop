/*****************************************************************************/
/*          FILE NAME        Image.h                                         */
/*          AUTHOR           Gen Oshiyama                                    */
/*          RELEASED AT      Dec 11, 2008                                    */
/*****************************************************************************/
/*          FileType         header file                                     */
/*          Context          struct Image                                    */
/*          Method           manage Image                                    */
/*****************************************************************************/
#ifndef __IP_IMAGE_H_
#define __IP_IMAGE_H_


typedef struct _Image
{
    unsigned char *buf;
    unsigned char **loc;
    int x, y;
} Image;

int getInt(FILE *fp);
void mallocImage(Image* image);
void loadImage(char* fname, Image* image);
void newImageFromSize(int x, int y, Image* image);
void newImageFromSizeOfImg(Image* src, Image* image);
void saveImage(char* fname, Image* image);
void freeImage(Image* image);
unsigned char getMaxValue(Image* img);

//double calcPsnr(Image* input, Ima

#endif // __IP_IMAGE_H_
