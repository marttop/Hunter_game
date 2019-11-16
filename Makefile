##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_hunter

SRC	=	src/start.c \
		src/event.c \
		src/display.c \
		src/render.c \

CFLAGS	+=	-l csfml-system
CFLAGS	+=	-l csfml-graphics
CFLAGS	+=	-l csfml-window
CFLAGS	+=	-I./include

all	:	$(NAME)

$(NAME)	:	$(SRC)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
