/*
** EPITECH PROJECT, 2019
** sounds
** File description:
** sounds file
*/

#include "../include/my.h"

int render_sound(sprites_s *s_display)
{
    s_display->sounds1.hit = sfMusic_createFromFile("sounds/hit.wav");
    if (!s_display->sounds1.hit)
        return (EXIT_FAILURE);
    return (0);
}