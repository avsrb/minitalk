SERVER	=	server

CLIENT	=	client

LIST_S	=	server.c utils.c

LIST_C	=	client.c utils.c ft_atoi.c

HEDEAR	=	minitalk.h

GCC		=	gcc -Wall -Wextra -Werror

OBJ_S	=	$(patsubst %.c, %.o, $(LIST_S))

OBJ_C	=	$(patsubst %.c, %.o, $(LIST_C))

all			:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ_S) $(HEADER)
	$(GCC) $(LIST_S) -o $(SERVER) 

$(CLIENT)	:	$(OBJ_C) $(HEADER)
	$(GCC) $(FLAGS) $(LIST_C) -o $(CLIENT)

clean		:
	@rm -f $(OBJ_S) $(OBJ_C)

fclean		:	clean
	@rm -f $(SERVER) $(CLIENT)

re			:	fclean all

.PHONY		:	all clean fclean re