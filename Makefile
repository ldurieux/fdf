NAME		= llx

SRCS		= \
			  main.c \
			  srcs/llx/destroy.c \
			  srcs/llx/exec.c \
			  srcs/llx/exit.c \
			  srcs/llx/init.c \
			  srcs/llx/on_loop.c \
			  srcs/llx/win/new.c \
			  srcs/llx/win/delete.c \
			  srcs/llx/win/event_handler_1.c \
			  srcs/llx/win/event_handler_2.c \
			  srcs/llx_paint/draw_tri.c \
			  srcs/llx_paint/paint_line.c \
			  srcs/llx_paint/draw_line_aa.c \
			  srcs/llx_paint/draw_line_aa_utils.c \
			  srcs/llx_paint/draw_line.c \
			  srcs/llx_paint/paint_tri.c \
			  srcs/llx_paint/paint_pixel.c \
			  srcs/llx_paint/is_in_bound.c \
			  srcs/llx_paint/paint_fill.c \
			  srcs/llx_paint/blend_pixel.c \

HEADERS		= \
			  includes \

CCDEFS		= \

ASMSRCS		= \

LIB_NAMES	= \
			  libft \
			  libmlx \
			  
DYN_LIBS	= \
			  #Xext \
			  #X11 \

FRAMEWORKS	= \
			  OpenGL \
			  AppKit \

DYN_LIBS	:= $(addprefix -l, $(DYN_LIBS))
FRAMEWORKS	:= $(addprefix -framework , $(FRAMEWORKS))

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CCDEFSFLGS	= $(foreach def,$(CCDEFS),-D $(def))

BUILDDIR	= build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) $(ASMSRCS:%.s=$(BUILDDIR)/%.o)
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d)
CC			= cc
CCWFLGS		= -Wall -Wextra
CCDBGFLGS	= -g3
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=native
CCO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir
AR			= ar
ARFLAGS		= rcs
NASM		= nasm
NASMFLAGS	= -felf64

all : $(NAME)

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CC) $(CCWFLGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(DYN_LIBS) $(FRAMEWORKS)

bonus : $(NAME)

$(LIB_PATHS) :
		$(MAKE) $(dir $@)

clean :
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

$(BUILDDIR)/%.o : %.s Makefile
		mkdir -p $(@D)
		$(NASM) $(NASMFLAGS) -o $(BUILDDIR)/$@ $<

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile
		mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(DEPSFLAGS) $(CCDBGFLGS) $(CCDEFSFLGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

.PHONY: all clean fclean re bonus
