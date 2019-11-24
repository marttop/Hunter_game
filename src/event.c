/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

void draw_dead(sprites_s *s_display, state *s_state)
{
    sfClock_restart(s_display->dead1.clock_pos);
    sfSprite_setPosition(s_display->dead1.dead_sprt,
    (sfVector2f){s_display->duck1.posx, s_display->duck1.posy});
    s_state->dead = 1;
}

void draw_dead_side(sprites_s *s_display, state *s_state)
{
    sfClock_restart(s_display->dead1.clock_pos);
    sfSprite_setPosition(s_display->dead1.dead_sprt,
    (sfVector2f){s_display->side1.posx, s_display->side1.posy});
    s_state->dead = 1;
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
        draw_dead(s_display, s_state);
        s_display->duck1.posx = 0;
        s_display->duck1.posy = rand() % 800;
        s_display->duck1.speed += 35;
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
        if (event.type == sfEvtMouseButtonPressed) {
            check_hitbox(s_display, window, s_state);
            check_hitbox_side(s_display, window, s_state);
        }
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