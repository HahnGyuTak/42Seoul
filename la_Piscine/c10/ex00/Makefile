CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCD = srcs/main.c

NAME = ft_display_file

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
