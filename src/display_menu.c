/*
** EPITECH PROJECT, 2019
** display
** File description:
** display
*/

#include "../include/my.h"

void display_menu(sfRenderWindow *window, sprites_s *s_display)
{
    sfRenderWindow_drawText(window, s_display->menu1.title_txt, NULL);
    sfRenderWindow_drawText(window, s_display->menu1.best_txt, NULL);
    sfRenderWindow_drawText(window, s_display->menu1.best_txt_int, NULL);
    sfRenderWindow_drawText(window, s_display->menu1.start_txt, NULL);
    display_dog(s_display, window);
    display_falling(s_display, window);
}

void display_dog(sprites_s *s_display, sfRenderWindow *window)
{
    sfSprite_setPosition(s_display->dog1.dog_sprt,
    (sfVector2f){s_display->dog1.posx, s_display->dog1.posy});
    sfSprite_setTextureRect(s_display->dog1.dog_sprt,
    s_display->dog1.rect_dog);
    if (s_display->dog1.seconds_anim > 0.08) {
        move_rect_dog(s_display, 130, 390);
        sfClock_restart(s_display->dog1.clock_anim);
    }
    sfRenderWindow_drawSprite(window, s_display->dog1.dog_sprt, NULL);
}