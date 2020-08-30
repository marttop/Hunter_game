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

<<<<<<< HEAD
CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-l csfml-system
CFLAGS	+=	-l csfml-graphics
CFLAGS	+=	-l csfml-audio
CFLAGS	+=	-l csfml-window
CFLAGS	+=	-I./include -g3
=======
CFLAGS	=	-Wall -Wextra -Werror
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS	+=	-I./include -g3
>>>>>>> b1d7dc91e688a73b2f7068a116fc8b0332494460

all	:	$(NAME)

$(NAME)	:	$(OBJ)
<<<<<<< HEAD
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
=======
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)
>>>>>>> b1d7dc91e688a73b2f7068a116fc8b0332494460

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
