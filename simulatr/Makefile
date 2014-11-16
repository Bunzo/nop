TARGET		=	asim
INCLUDES	=	-I./include
LDFLAGS		=	
NOMAKEDIR	=	.git% .svn%
OBJDIR		=	./obj

CC			=	gcc48
CFLAGS		=	-O2

ALLC		=	$(shell find . -name *.c)
SRCS		=	$(filter-out $(NOMAKEDIR), $(ALLC))
DIRS		=	$(dir $(SRCS))
BINDIRS		=	$(addprefix $(OBJDIR)/, $(DIRS))

OBJS		=	$(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(SRCS)))
DEPS		=	$(OBJS:.o=.d)
TILS		=	$(patsubst %.c, %.c~, $(SRCS))

MAKE		=	gmake

ifeq "$(strip $(OBJDIR))" ""
	OBJDIR	=	.
endif

ifeq "$(strip $(DIRS))" ""
	OBJDIR	=	.
endif

default:
	@[ -d  $(OBJDIR)   ] || mkdir -p $(OBJDIR)
	@[ -d "$(BINDIRS)" ] || mkdir -p $(BINDIRS)
	@$(MAKE) all

all : $(OBJS) $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:;	@rm -rf $(TARGET) $(TILS) $(OBJDIR)

-include $(DEPS)
