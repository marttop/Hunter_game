/*
** EPITECH PROJECT, 2019
** render
** File description:
** rendering sprites
*/

#include "../include/my.h"

int render_score_txt(sprites_s *s_display)
{
    s_display->score1.font_score_txt = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->score1.font_score_txt)
        return (EXIT_FAILURE);
    s_display->score1.text_score_txt = sfText_create();
    sfText_setString(s_display->score1.text_score_txt, "Score :");
    sfText_setFont(s_display->score1.text_score_txt,
    s_display->score1.font_score_txt);
    sfText_setCharacterSize(s_display->score1.text_score_txt, 50);
    sfText_setPosition(s_display->score1.text_score_txt,
    (sfVector2f){1550, 0});
}

int render_score_int(sprites_s *s_display, state *s_state)
{
    s_display->score1.font_score_int = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->score1.font_score_int)
        return (EXIT_FAILURE);
    s_state->str_score = my_put_strnbr(s_state->score);
    s_display->score1.text_score_int = sfText_create();
    sfText_setString(s_display->score1.text_score_int, s_state->str_score);
    sfText_setFont(s_display->score1.text_score_int,
    s_display->score1.font_score_int);
    sfText_setCharacterSize(s_display->score1.text_score_int, 50);
    sfText_setPosition(s_display->score1.text_score_int,
    (sfVector2f){1800, 5});
}

int render_duck(sprites_s *s_display, sfIntRect *rect,
                sfVideoMode mode)
{
    s_display->duck1.clock_anim = sfClock_create();
    s_display->duck1.clock_pos = sfClock_create();
    rect->left = 0, rect->top = 0, rect->width = 110, rect->height = 110;
    s_display->duck1.duck_txt =
    sfTexture_createFromFile("sprites/duck.png", NULL);
    if (!s_display->duck1.duck_txt)
        return (EXIT_FAILURE);
    s_display->duck1.duck_sprt = sfSprite_create();
}

int render_background(sfRenderWindow *window, sprites_s *s_display,
                        sfVideoMode mode)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    s_display->background1.background_txt =
    sfTexture_createFromFile("sprites/duck_background.png", NULL);
    if (!s_display->background1.background_txt)
        return (EXIT_FAILURE);
    s_display->background1.background_sprt = sfSprite_create();
    sfSprite_setTexture(s_display->background1.background_sprt,
    s_display->background1.background_txt, sfTrue);
}

void load_clocks(sprites_s *s_display)
{
    s_display->duck1.time_anim =
    sfClock_getElapsedTime(s_display->duck1.clock_anim);
    s_display->duck1.time_pos =
    sfClock_getElapsedTime(s_display->duck1.clock_pos);
    s_display->duck1.seconds_anim =
    s_display->duck1.time_anim.microseconds / 1000000.0;
    s_display->duck1.seconds_pos =
    s_display->duck1.time_pos.microseconds / 1000000.0;
}