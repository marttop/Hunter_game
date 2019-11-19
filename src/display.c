/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void permanent_displays(sfRenderWindow *window, state *s_state,
                        sprites_s* s_display, sfIntRect *rect)
{
    sfRenderWindow_clear(window, sfBlack);
    if (s_state->my_state == 1) {
        sfRenderWindow_drawSprite(window,
        s_display->background1.background_sprt, NULL);
        display_duck(s_display, window, rect);
        display_score(s_display, window);
        display_timer(s_display, window, s_state);
    }
    else
        display_game_over(s_display, window);
    sfRenderWindow_display(window);
}

void display_timer(sprites_s *s_display, sfRenderWindow *window,
                    state *s_state)
{
    if (s_display->timer1.seconds_timer > 1.0) {
        if (s_display->timer1.strtime != NULL)
            free(s_display->timer1.strtime);
        s_display->timer1.time -= 1;
        s_display->timer1.strtime = my_put_strnbr(s_display->timer1.time);
        sfClock_restart(s_display->timer1.timer_clock);
    }
    if (s_display->timer1.time < 0)
        s_state->my_state = 0;
    sfText_setString(s_display->timer1.text_timer, s_display->timer1.strtime);
    sfRenderWindow_drawText(window, s_display->timer1.text_timer, NULL);
}

void display_score(sprites_s *s_display, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, s_display->score1.text_score_txt, NULL);
    sfRenderWindow_drawText(window, s_display->score1.text_score_int, NULL);
}

void display_duck(sprites_s *s_display, sfRenderWindow *window,
                    sfIntRect *rect)
{
    if (s_display->duck1.seconds_anim > 0.1) {
        move_rect(rect, 110, 330);
        sfClock_restart(s_display->duck1.clock_anim);
    }
    sfRenderWindow_drawSprite(window, s_display->duck1.duck_sprt, NULL);
}

void display_game_over(sprites_s *s_display, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, s_display->g_over.over_txt, NULL);
    sfRenderWindow_drawText(window, s_display->g_over.your_text, NULL);
    sfText_setPosition(s_display->score1.text_score_int,
    (sfVector2f){1180, 505});
    sfRenderWindow_drawText(window, s_display->score1.text_score_int, NULL);
}