CC       = gcc
CFLAGS   = -g -Wall -I.
OPTFLAGS = -O3
LIBS     =
LDFLAGS  = -lm

OBJS     = Image.o Block.o psnr.o dct2.o stereo.o main.o
TARGET   = main
RM       = rm -f

#DEBUG    = -DDEBUG
#DEBUG    =

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OPTFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS) $(DEBUG)

.c.o:
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< $(DEBUG)

clean:
	$(RM) $(OBJS) $(TARGET) $(FILE)



image:
	convert -quality 100 Lenna.jpg Lenna100.jpg
	convert -quality 95 Lenna.jpg Lenna95.jpg
	convert -quality 90 Lenna.jpg Lenna90.jpg
	convert -quality 85 Lenna.jpg Lenna85.jpg
	convert -quality 80 Lenna.jpg Lenna80.jpg
	convert -quality 75 Lenna.jpg Lenna75.jpg
	convert -quality 70 Lenna.jpg Lenna70.jpg
	convert -quality 65 Lenna.jpg Lenna65.jpg
	convert -quality 60 Lenna.jpg Lenna60.jpg
	convert -quality 55 Lenna.jpg Lenna55.jpg
	convert -quality 50 Lenna.jpg Lenna50.jpg
	convert -quality 45 Lenna.jpg Lenna45.jpg
	convert -quality 40 Lenna.jpg Lenna40.jpg
	convert -quality 35 Lenna.jpg Lenna35.jpg
	convert -quality 30 Lenna.jpg Lenna30.jpg
	convert -quality 25 Lenna.jpg Lenna25.jpg
	convert -quality 20 Lenna.jpg Lenna20.jpg
	convert -quality 15 Lenna.jpg Lenna15.jpg
	convert -quality 10 Lenna.jpg Lenna10.jpg
	convert -quality 5 Lenna.jpg Lenna5.jpg
	convert -quality 1 Lenna.jpg Lenna1.jpg

	convert Lenna.jpg Lenna.pgm
	convert Lenna100.jpg Lenna100.pgm
	convert Lenna95.jpg Lenna95.pgm
	convert Lenna90.jpg Lenna90.pgm
	convert Lenna85.jpg Lenna85.pgm
	convert Lenna80.jpg Lenna80.pgm
	convert Lenna75.jpg Lenna75.pgm
	convert Lenna70.jpg Lenna70.pgm
	convert Lenna65.jpg Lenna65.pgm
	convert Lenna60.jpg Lenna60.pgm
	convert Lenna55.jpg Lenna55.pgm
	convert Lenna50.jpg Lenna50.pgm
	convert Lenna45.jpg Lenna45.pgm
	convert Lenna40.jpg Lenna40.pgm
	convert Lenna35.jpg Lenna35.pgm
	convert Lenna30.jpg Lenna30.pgm
	convert Lenna25.jpg Lenna25.pgm
	convert Lenna20.jpg Lenna20.pgm
	convert Lenna15.jpg Lenna15.pgm
	convert Lenna10.jpg Lenna10.pgm
	convert Lenna5.jpg Lenna5.pgm
	convert Lenna1.jpg Lenna1.pgm

psnr:
	./main --psnr Lenna.pgm Lenna100.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna95.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna90.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna85.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna80.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna75.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna70.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna65.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna60.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna55.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna50.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna45.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna40.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna35.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna30.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna25.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna20.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna15.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna10.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna5.pgm >> psnr.log
	./main --psnr Lenna.pgm Lenna1.pgm >> psnr.log

dct2:
	./main --varDCT2 Lenna.pgm > dct2.log

disp:
	./main --disp left-g.pgm right-g.pgm dispLR-g.pgm

# End Of File
