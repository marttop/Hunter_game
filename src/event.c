/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void manage_mouse_click(sfMouseButtonEvent event, sfRenderWindow *window)
{
    const sfWindow *w_window = window;
    sfMouse_getPosition(w_window).x;
    sfMouse_getPosition(w_window).y;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        rect->left += 110;
    }
    else {
        rect->left = 0;
    }
}

void move_duck(sprites_s *s_display)
{
    if (s_display->duck1.posx < 1920)
        s_display->duck1.posx += s_display->duck1.speed *
        s_display->duck1.seconds_pos;
    else {
        s_display->duck1.posx = 0;
        s_display->duck1.posy = rand() % 800;
    }
    sfClock_restart(s_display->duck1.clock_pos);
}

void check_hitbox(sprites_s *s_display, sfRenderWindow *window, state *s_state)
{
    s_state->mouse_posx = sfMouse_getPositionRenderWindow(window).x;
    s_state->mouse_posy = sfMouse_getPositionRenderWindow(window).y;
    if ((s_state->mouse_posx > s_display->duck1.posx &&
    s_state->mouse_posx < s_display->duck1.posx + 110) &&
    s_state->mouse_posy > s_display->duck1.posy &&
    s_state->mouse_posy < s_display->duck1.posy + 110) {
        if (s_state->str_score != NULL)
            free(s_state->str_score);
        s_state->score += 1;
        s_state->str_score = my_put_strnbr(s_state->score);
        s_display->duck1.posx = 0;
        s_display->duck1.posy = rand() % 800;
        s_display->duck1.speed += 140;
        sfText_setString(s_display->score1.text_score_int, s_state->str_score);
        sfText_setFont(s_display->score1.text_score_int,
        s_display->score1.font_score_int);
    }
}

void analyse_event(sfRenderWindow *window, sfEvent event, state *s_state,
                    sprites_s *s_display)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        check_hitbox(s_display, window, s_state);
    }
}