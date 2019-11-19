/*
** EPITECH PROJECT, 2019
** render
** File description:
** render2
*/

#include "../include/my.h"

int render_timer_int(sprites_s *s_display)
{
    s_display->timer1.timer_clock = sfClock_create();
    s_display->timer1.time = 15;
    s_display->timer1.font_timer = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->timer1.font_timer)
        return (EXIT_FAILURE);
    s_display->timer1.strtime = my_put_strnbr(s_display->timer1.time);
    s_display->timer1.text_timer = sfText_create();
    sfText_setString(s_display->timer1.text_timer, s_display->timer1.strtime);
    sfText_setFont(s_display->timer1.text_timer, s_display->timer1.font_timer);
    sfText_setCharacterSize(s_display->timer1.text_timer, 50);
    sfText_setPosition(s_display->timer1.text_timer, (sfVector2f){935, 5});
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
    sfText_setPosition(s_display->g_over.over_txt, (sfVector2f){780, 200});
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
    "Left clic to restart, right clic to exit");
    sfText_setFont(s_display->g_over.restart_txt, s_display->g_over.restart_font);
    sfText_setCharacterSize(s_display->g_over.restart_txt, 50);
    sfText_setPosition(s_display->g_over.restart_txt, (sfVector2f){450, 570});
    return (0);
}