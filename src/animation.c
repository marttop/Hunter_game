/*
** EPITECH PROJECT, 2019
** animation
** File description:
** animation
*/

#include "../include/my.h"

void move_rect_duck(sprites_s *s_display, int offset, int max_value)
{
    if (s_display->duck1.rect_duck.left < max_value - offset) {
        s_display->duck1.rect_duck.left += offset;
    }
    else
        s_display->duck1.rect_duck.left = 0;
}

void move_rect_dog(sprites_s *s_display, int offset, int max_value)
{
    if (s_display->dog1.rect_dog.left < max_value - offset) {
        s_display->dog1.rect_dog.left += offset;
    }
    else
        s_display->dog1.rect_dog.left = 0;
}

void move_duck(sprites_s *s_display)
{
    if (s_display->duck1.posx < 1920) {
        s_display->duck1.posx += s_display->duck1.speed *
        s_display->duck1.seconds_pos;
    }
    else {
        s_display->duck1.posx = 0;
        s_display->duck1.posy = rand() % 800;
        s_display->lives1.lives -= 1;
        s_display->lives1.strlives = my_put_strnbr(s_display->lives1.lives);
    }
    sfClock_restart(s_display->duck1.clock_pos);
}

void move_dog(sprites_s *s_display)
{
    if (s_display->dog1.posx < 1120) {
        s_display->dog1.posx += 50 * s_display->dog1.seconds_pos;
    }
    else {
        s_display->dog1.posx = 650;
    }
    sfClock_restart(s_display->dog1.clock_pos);
}