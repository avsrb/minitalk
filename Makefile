SERVER	=	server

CLIENT	=	client

SERVER_B	=	server_bonus

CLIENT_B	=	client_bonus

LIST_S	=	server.c utils.c

LIST_C	=	client.c utils.c ft_atoi.c

LIST_S_B	=	server_bonus.c utils_bonus.c

LIST_C_B	=	client_bonus.c utils_bonus.c ft_atoi_bonus.c

HEDEAR	=	minitalk.h

HEDEAR_B	=	minitalk_bonus.h

GCC		=	gcc -Wall -Wextra -Werror

OBJ_S	=	$(patsubst %.c, %.o, $(LIST_S))

OBJ_C	=	$(patsubst %.c, %.o, $(LIST_C))

OBJ_S_B	=	$(patsubst %.c, %.o, $(LIST_S_B))

OBJ_C_B	=	$(patsubst %.c, %.o, $(LIST_C_B))

all			:	$(SERVER) $(CLIENT)

bonus		:	$(SERVER_B) $(CLIENT_B)

$(SERVER)	:	$(OBJ_S) $(HEADER)
	$(GCC) $(FLAGS) $(LIST_S) -o $(SERVER) 

$(CLIENT)	:	$(OBJ_C) $(HEADER)
	$(GCC) $(FLAGS) $(LIST_C) -o $(CLIENT)

$(SERVER_B)	:	$(OBJ_S_B) $(HEADER_B)
	$(GCC) $(FLAGS) $(LIST_S_B) -o $(SERVER_B) 

$(CLIENT_B)	:	$(OBJ_C_B) $(HEADER_B)
	$(GCC) $(FLAGS) $(LIST_C_B) -o $(CLIENT_B)

clean		:
	@rm -f ./*.o

fclean		:	clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re			:	fclean all

.PHONY		:	all clean fclean re