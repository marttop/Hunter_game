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
		utils/score.c \
		src/destroy.c \
		src/render_menu.c \
		src/display_menu.c \
		src/animation.c \
		src/clocks.c \
		src/display2.c \
		src/falling.c \
		src/side_duck.c \
		src/restart.c \
		src/sounds.c \
		src/crosshair.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS	+=	-I./include -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
