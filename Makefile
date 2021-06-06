NAME	=	minitalk

LIST	=	server.c client.c utils.c

HEADER	=	minitalk.h

OBJ		=	$(patsubst %.c, %.0, $(LIST))

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:
	rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re