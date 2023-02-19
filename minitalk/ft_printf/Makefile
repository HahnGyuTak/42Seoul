CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTFILE = libft.a

RM = rm -rf

SRCS = \
	ft_print_address.c	\
	ft_print_hex.c	\
	ft_print_number.c	\
	ft_print_string.c	\
	ft_printf.c		\

INC = ft_printf.h

OBJS = $(SRCS:.c=.o)

OBJ_FILES = $(OBJS)

all : $(NAME)
%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	ar crs $(NAME) $(OBJ_FILES)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : fclean $(NAME)
.PHONY : all clean fclean re
