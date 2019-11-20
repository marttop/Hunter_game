/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

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
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (s_state->my_state == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            check_hitbox(s_display, window, s_state);
    }
    if (s_state->my_state == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            restart(s_state, s_display);
    }
    if (s_state->my_state == 2) {
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            restart(s_state, s_display);
    }
}

void restart(state *s_state, sprites_s *s_display)
{
    write_score(s_state);
    s_state->score = 0;
    sfText_setString(s_display->score1.text_score_int, "0");
    s_display->duck1.posx = 0;
    s_display->duck1.posy = 0;
    s_display->duck1.speed = 500;
    sfText_setPosition(s_display->score1.text_score_int,
    (sfVector2f){1800, 5});
    sfClock_restart(s_display->duck1.clock_anim);
    sfClock_restart(s_display->duck1.clock_pos);
    sfClock_restart(s_display->timer1.timer_clock);
    s_display->timer1.time = 15;
    s_state->my_state = 1;
}