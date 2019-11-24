/*
** EPITECH PROJECT, 2019
** falling
** File description:
** falling
*/

#include "../include/my.h"

void move_rect_falling(sprites_s *s_display, int offset, int max_value)
{
    if (s_display->falling1.rect_duck.left < max_value - offset) {
        s_display->falling1.rect_duck.left += offset;
    }
    else
        s_display->falling1.rect_duck.left = 0;
}

void move_falling(sprites_s *s_display)
{
    if (s_display->falling1.posy < 1080)
        s_display->falling1.posy += 800 * s_display->falling1.seconds_pos;
    else {
        s_display->falling1.posy = 0;
        s_display->falling1.posx = rand() % 1700;
    }
    sfClock_restart(s_display->falling1.clock_pos);
}