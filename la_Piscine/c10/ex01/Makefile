CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCD = srcs/main.c srcs/ft_putstr.c srcs/ft_putchar.c srcs/ft_read_file.c srcs/ft_strlen.c srcs/ft_error.c

NAME = ft_cat
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
