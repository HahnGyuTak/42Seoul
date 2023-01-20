SERVER = server
CLIENT = clinet

CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
		

FT_PRINTF = make -C ft_printf

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all :	$(SERVER) $(CLIENT)

$(SERVER) :	$(OBJS_SERVER)
			$(FT_PRINTF)
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) ft_printf/libftprintf.a

$(CLIENT) :	$(OBJS_CLIENT)
			$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) ft_printf/libftprintf.a

clean   :
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
			make -C ft_printf clean

fclean  :	clean
			$(RM) server client ft_printf/libftprintf.a

re  :	fclean all

.PHONY  :	all clean fclean re