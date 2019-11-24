/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void permanent_displays(sfRenderWindow *window, state *s_state,
                        sprites_s* s_display)
{
    sfRenderWindow_clear(window, sfBlack);
    if (s_state->my_state == 1) {
        sfRenderWindow_drawSprite(window,
        s_display->background1.background_sprt, NULL);
        display_duck(s_display, window, s_state);
        display_side(s_display, window, s_state);
        display_score(s_display, window);
        display_lives(s_display, window, s_state);
    }
    else if (s_state->my_state == 0)
        display_game_over(s_display, window);
    else
        display_menu(window, s_display);
    sfRenderWindow_display(window);
}

void display_lives(sprites_s *s_display, sfRenderWindow *window,
                    state *s_state)
{
    if (s_display->lives1.lives < 0)
        s_state->my_state = 0;
    sfText_setString(s_display->lives1.text_lives, s_display->lives1.strlives);
    sfRenderWindow_drawText(window, s_display->lives1.text_lives, NULL);
}

void display_score(sprites_s *s_display, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, s_display->score1.text_score_txt, NULL);
    sfRenderWindow_drawText(window, s_display->score1.text_score_int, NULL);
}

void display_duck(sprites_s *s_display, sfRenderWindow *window, state *s_state)
{
    sfSprite_setPosition(s_display->duck1.duck_sprt,
    (sfVector2f){s_display->duck1.posx, s_display->duck1.posy});
    sfSprite_setTextureRect(s_display->duck1.duck_sprt,
    s_display->duck1.rect_duck);
    if (s_display->duck1.seconds_anim > 0.1) {
        move_rect_duck(s_display, 110, 330);
        sfClock_restart(s_display->duck1.clock_anim);
    }
    sfRenderWindow_drawSprite(window, s_display->duck1.duck_sprt, NULL);
    display_dead(window, s_state, s_display);
}

void display_game_over(sprites_s *s_display, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, s_display->g_over.over_txt, NULL);
    sfRenderWindow_drawText(window, s_display->g_over.your_text, NULL);
    sfText_setPosition(s_display->score1.text_score_int,
    (sfVector2f){1180, 505});
    sfRenderWindow_drawText(window, s_display->score1.text_score_int, NULL);
    sfRenderWindow_drawText(window, s_display->g_over.restart_txt, NULL);
}