# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 23:39:38 by ple-thie          #+#    #+#              #
#    Updated: 2022/06/09 10:39:21 by sehjung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CC_FLAGS = -c -Werror -Wall -Wextra
SOURCES = src/main.c src/file.c src/ft_strcat.c src/ft_putchar.c \
		  src/ft_putstr.c src/ft_atoi.c src/ft_strlen.c \
		  src/ft_strncat.c src/ft_putnbr.c src/converter.c \
		  src/square_finder.c src/ft_map_error.c
INCL = src/main.h src/map.h src/tools.h
OBJ = main.o file.o ft_strcat.o ft_putchar.o ft_putstr.o ft_atoi.o ft_strlen.o \
	  ft_strncat.o ft_putnbr.o converter.o square_finder.o ft_map_error.o

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -I INCL $(SOURCES)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f grid.txt grid1.txt
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: fclean all grid
	./bsq grid.txt grid1.txt
	cat grid.txt | ./bsq

grid:
	perl generate.pl 10 10 3 > grid.txt
	perl generate.pl 15 15 5 > grid1.txt
