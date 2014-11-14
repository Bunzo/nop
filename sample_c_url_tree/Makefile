CC       = gcc
CFLAGS   = -g -Wall -I.
OPTFLAGS = -O3
LIBS     =
LDFLAGS  = -lm

OBJS     = Search.o Node.o Cons.o Map.o main.o
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
	$(RM) $(OBJS) $(TARGET) *.exe