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
    if (s_state->dead == 1) {
        sfRenderWindow_drawSprite(window, s_display->dead1.dead_sprt, NULL);
    }
}

void display_dead_side(sfRenderWindow *window, state *s_state, sprites_s *s_display)
{
    if (s_display->dead1.seconds_pos > 0.1) {
        s_state->dead = 0;
    }
    if (s_state->dead == 1) {
        sfRenderWindow_drawSprite(window, s_display->dead1.dead_sprt, NULL);
    }
}

void display_falling(sprites_s *s_display, sfRenderWindow *window)
{
    sfSprite_setPosition(s_display->falling1.duck_sprt,
    (sfVector2f){s_display->falling1.posx, s_display->falling1.posy});
    sfSprite_setTextureRect(s_display->falling1.duck_sprt,
    s_display->falling1.rect_duck);
    if (s_display->falling1.seconds_anim > 0.1) {
        move_rect_falling(s_display, 110, 220);
        sfClock_restart(s_display->falling1.clock_anim);
    }
    sfRenderWindow_drawSprite(window, s_display->falling1.duck_sprt, NULL);
}