CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCD = srcs/main.c srcs/ft_atoi.c srcs/ft_add.c srcs/ft_sub.c srcs/ft_mul.c srcs/ft_div.c srcs/ft_mod.c srcs/ft_putnbr.c

NAME = do-op
OBJECT = $(SRCD:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT)
clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(NAME)

re : fclean all
.PHONY:	all clean fclean re
