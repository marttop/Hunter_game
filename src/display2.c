/*
** EPITECH PROJECT, 2019
** display2
** File description:
** display2
*/

#include "../include/my.h"

void display_dead(sfRenderWindow *window, state *s_state, sprites_s *s_display)
{
    if (s_display->dead1.seconds_pos > 0.1) {
        s_state->dead = 0;
    }
    if (s_state->dead == 1)
        sfRenderWindow_drawSprite(window, s_display->dead1.dead_sprt, NULL);
}