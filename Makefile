##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make to file
##

SRC     =	my_hunter.c			\

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -Wall -W -Wextra -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

re:	fclean all

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
