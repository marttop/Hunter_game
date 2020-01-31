/*
** EPITECH PROJECT, 2019
** crossair
** File description:
** crossair
*/

#include "../include/my.h"

int render_crosshair(sprites_s *s_display)
{
    s_display->cross1.cross_txt =
    sfTexture_createFromFile("sprites/cross.png", NULL);
    if (!s_display->cross1.cross_txt)
        return (EXIT_FAILURE);
    s_display->cross1.cross_sprt = sfSprite_create();
    sfSprite_setTexture(s_display->cross1.cross_sprt,
    s_display->cross1.cross_txt, sfTrue);
    return (0);
}

void display_crosshair(sprites_s *s_display, sfRenderWindow *window,
                        state *s_state)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    s_state->mouse_posx = sfMouse_getPositionRenderWindow(window).x;
    s_state->mouse_posy = sfMouse_getPositionRenderWindow(window).y;
    sfSprite_setPosition(s_display->cross1.cross_sprt,
    (sfVector2f){s_state->mouse_posx - 36, s_state->mouse_posy - 36});
    sfRenderWindow_drawSprite(window, s_display->cross1.cross_sprt, NULL);
}