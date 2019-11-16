/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void manage_mouse_click(sfMouseButtonEvent event, sfRenderWindow *window)
{
    const sfWindow *w_window = window;
    sfMouse_getPosition(w_window).x;
    sfMouse_getPosition(w_window).y;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        rect->left += 110;
    }
    else {
        rect->left = 0;
    }
}

void move_duck(sprites_s *s_display)
{
    if (s_display->duck1.posx < 1920)
        s_display->duck1.posx += 800 * s_display->duck1.seconds_pos;
    else
        s_display->duck1.posx = 0;
    sfClock_restart(s_display->duck1.clock_pos);
}

void analyse_event(sfRenderWindow *window, sfEvent event, state *s_state)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue){
        s_state->my_state = 0;
    }
}