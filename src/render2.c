/*
** EPITECH PROJECT, 2019
** render
** File description:
** render2
*/

#include "../include/my.h"

int render_timer_int(sprites_s *s_display)
{
    s_display->lives1.lives = 5;
    s_display->lives1.font_lives = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->lives1.font_lives)
        return (EXIT_FAILURE);
    s_display->lives1.strlives = my_put_strnbr(s_display->lives1.lives);
    s_display->lives1.text_lives = sfText_create();
    sfText_setString(s_display->lives1.text_lives, s_display->lives1.strlives);
    sfText_setFont(s_display->lives1.text_lives, s_display->lives1.font_lives);
    sfText_setCharacterSize(s_display->lives1.text_lives, 50);
    sfText_setPosition(s_display->lives1.text_lives, (sfVector2f){935, 5});
    return (0);
}

int render_game_over(sprites_s *s_display)
{
    s_display->g_over.over_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->g_over.over_font)
        return (EXIT_FAILURE);
    s_display->g_over.over_txt = sfText_create();
    sfText_setString(s_display->g_over.over_txt, "GAME\nOVER");
    sfText_setFont(s_display->g_over.over_txt, s_display->g_over.over_font);
    sfText_setCharacterSize(s_display->g_over.over_txt, 100);
    sfText_setPosition(s_display->g_over.over_txt, (sfVector2f){760, 200});
    return (0);
}

int render_your_score(sprites_s *s_display)
{
    s_display->g_over.your_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->g_over.your_font)
        return (EXIT_FAILURE);
    s_display->g_over.your_text = sfText_create();
    sfText_setString(s_display->g_over.your_text, "Your final score is :");
    sfText_setFont(s_display->g_over.your_text, s_display->g_over.your_font);
    sfText_setCharacterSize(s_display->g_over.your_text, 50);
    sfText_setPosition(s_display->g_over.your_text, (sfVector2f){600, 500});
    return (0);
}

int render_restart(sprites_s *s_display)
{
    s_display->g_over.restart_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->g_over.restart_font)
        return (EXIT_FAILURE);
    s_display->g_over.restart_txt = sfText_create();
    sfText_setString(s_display->g_over.restart_txt,
    "R to restart, ESC to close");
    sfText_setFont(s_display->g_over.restart_txt,
    s_display->g_over.restart_font);
    sfText_setCharacterSize(s_display->g_over.restart_txt, 50);
    sfText_setPosition(s_display->g_over.restart_txt, (sfVector2f){550, 570});
    return (0);
}

int render_dead(sprites_s *s_display)
{
    s_display->dead1.clock_pos = sfClock_create();
    s_display->dead1.dead_txt =
    sfTexture_createFromFile("sprites/Die.png", NULL);
    if (!s_display->duck1.duck_txt)
        return (EXIT_FAILURE);
    s_display->dead1.dead_sprt = sfSprite_create();
    sfSprite_setTexture(s_display->dead1.dead_sprt,
    s_display->dead1.dead_txt, sfTrue);
    return (0);
}