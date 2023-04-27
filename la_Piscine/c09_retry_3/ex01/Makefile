CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs
SRCD = $(SRCS)/ft_putchar.c $(SRCS)/ft_swap.c $(SRCS)/ft_putstr.c $(SRCS)/ft_strlen.c $(SRCS)/ft_strcmp.c
INCLUDED = includes
NAME = libft.a

OBJECT = $(SRCD:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDED)

$(NAME) : $(OBJECT)
	ar -rc $@ $(OBJECT)

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(NAME)
re : fclean all
