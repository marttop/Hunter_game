/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void permanent_displays(sfRenderWindow *window, state *s_state,
                        sprites_s* s_display, sfIntRect *rect)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, s_display->background1.background_sprt,
    NULL);
    if (s_state->my_state == 1) {
        if (s_display->duck1.seconds_anim > 0.1) {
            move_rect(rect, 110, 330);
            sfClock_restart(s_display->duck1.clock_anim);
        }
        sfRenderWindow_drawSprite(window, s_display->duck1.duck_sprt, NULL);
    }
}