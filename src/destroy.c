/*
** EPITECH PROJECT, 2019
** detroy
** File description:
** destroying all
*/

#include "../include/my.h"

void destroy_all(sfRenderWindow *window, sprites_s *s_display, state *s_state)
{
    free(s_display->lives1.strlives), free(s_state->str_score);
    sfSprite_destroy(s_display->duck1.duck_sprt);
    sfSprite_destroy(s_display->background1.background_sprt);
    sfTexture_destroy(s_display->duck1.duck_txt);
    sfTexture_destroy(s_display->background1.background_txt);
    sfFont_destroy(s_display->score1.font_score_int);
    sfFont_destroy(s_display->score1.font_score_txt);
    sfFont_destroy(s_display->lives1.font_lives);
    sfFont_destroy(s_display->g_over.over_font);
    sfFont_destroy(s_display->g_over.your_font);
    sfText_destroy(s_display->score1.text_score_int);
    sfText_destroy(s_display->score1.text_score_txt);
    sfText_destroy(s_display->lives1.text_lives);
    sfText_destroy(s_display->g_over.over_txt);
    sfText_destroy(s_display->g_over.your_text);
    sfClock_destroy(s_display->duck1.clock_anim);
    sfClock_destroy(s_display->duck1.clock_pos);
    destroy_next(s_display);
    sfRenderWindow_destroy(window);
}

void destroy_next(sprites_s *s_display)
{
    sfText_destroy(s_display->g_over.restart_txt);
    sfText_destroy(s_display->menu1.title_txt);
    sfText_destroy(s_display->menu1.best_txt);
    sfText_destroy(s_display->menu1.best_txt_int);
    sfText_destroy(s_display->menu1.start_txt);
    sfFont_destroy(s_display->g_over.restart_font);
    sfFont_destroy(s_display->menu1.title_font);
    sfFont_destroy(s_display->menu1.best_font);
    sfFont_destroy(s_display->menu1.best_font_int);
    sfFont_destroy(s_display->menu1.start_font);
    sfSprite_destroy(s_display->dog1.dog_sprt);
    sfSprite_destroy(s_display->dead1.dead_sprt);
    sfTexture_destroy(s_display->dog1.dog_txt);
    sfTexture_destroy(s_display->dead1.dead_txt);
    sfClock_destroy(s_display->dog1.clock_pos);
    sfClock_destroy(s_display->dog1.clock_anim);
    sfClock_destroy(s_display->dead1.clock_pos);
    destroy_second(s_display);
}

void destroy_second(sprites_s *s_display)
{
    sfClock_destroy(s_display->falling1.clock_anim);
    sfClock_destroy(s_display->falling1.clock_pos);
    sfClock_destroy(s_display->side1.clock_anim);
    sfClock_destroy(s_display->side1.clock_pos);
    sfTexture_destroy(s_display->falling1.duck_txt);
    sfTexture_destroy(s_display->side1.duck_txt);
    sfTexture_destroy(s_display->cross1.cross_txt);
    sfSprite_destroy(s_display->falling1.duck_sprt);
    sfSprite_destroy(s_display->side1.duck_sprt);
    sfSprite_destroy(s_display->cross1.cross_sprt);
    sfMusic_destroy(s_display->sounds1.hit);
}