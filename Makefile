##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile
##

SRCS	=	src/page.c

OBJ 	= 	$(subst .c,.o,$(SRCS))

NAME 	=	my_rpg

all 	: 	$(NAME)

$(NAME) :	$(SRCS)
		gcc -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-window \
                -lcsfml-system -lcsfml-audio -lm


clean 	:
		rm -f $(OBJ)

fclean 	: 	clean
		rm -f $(NAME)

re 	: 	fclean all
