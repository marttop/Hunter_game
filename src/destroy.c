/*
** EPITECH PROJECT, 2019
** detroy
** File description:
** destroying all
*/

#include "../include/my.h"

void destroy_all(sfRenderWindow *window, sprites_s *s_display, state *s_state)
{
    free(s_display->timer1.strtime), free(s_state->str_score);
    sfSprite_destroy(s_display->duck1.duck_sprt);
    sfSprite_destroy(s_display->background1.background_sprt);
    sfTexture_destroy(s_display->duck1.duck_txt);
    sfTexture_destroy(s_display->background1.background_txt);
    sfFont_destroy(s_display->score1.font_score_int);
    sfFont_destroy(s_display->score1.font_score_txt);
    sfFont_destroy(s_display->timer1.font_timer);
    sfFont_destroy(s_display->g_over.over_font);
    sfFont_destroy(s_display->g_over.your_font);
    sfText_destroy(s_display->score1.text_score_int);
    sfText_destroy(s_display->score1.text_score_txt);
    sfText_destroy(s_display->timer1.text_timer);
    sfText_destroy(s_display->g_over.over_txt);
    sfText_destroy(s_display->g_over.your_text);
    sfClock_destroy(s_display->duck1.clock_anim);
    sfClock_destroy(s_display->duck1.clock_pos);
    sfClock_destroy(s_display->timer1.timer_clock);
    sfRenderWindow_destroy(window);
    destroy_next(s_display);
}

void destroy_next(sprites_s *s_display)
{
    sfText_destroy(s_display->g_over.restart_txt);
    sfFont_destroy(s_display->g_over.restart_font);
}