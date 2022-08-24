CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
RM = rm -rf

SRCS = \
	srcs/ft_itoa.c	\
	srcs/ft_strlen.c	\
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
	$(CC) $(CFLAG) -c $< -o $@
$(NAME) : $(OBJ_FILES)
	ar crs $(NAME) $(OBJ_FILES)
clean : 
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean $(NAME)
.PHONY : all clean fclean re
