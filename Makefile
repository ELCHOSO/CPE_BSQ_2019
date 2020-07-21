##
## EPITECH PROJECT, 2019
## BSQ
## File description:
## Makefile
##

SRC	=	fonctions/algo_change_tab.c			\
		fonctions/map_dimension.c			\
		fonctions/put_map_in_tab.c			\
		fonctions/get_corner.c				\
		fonctions/main.c				\
		fonctions/error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
