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
		utils/my_put_strnbr.c \
		src/render2.c \
		src/score.c \
		src/destroy.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-l csfml-system
CFLAGS	+=	-l csfml-graphics
CFLAGS	+=	-l csfml-window
CFLAGS	+=	-I./include -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
