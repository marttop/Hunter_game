/*
** EPITECH PROJECT, 2019
** restart
** File description:
** restart event
*/

#include "../include/my.h"

void restart(state *s_state, sprites_s *s_display)
{
    write_score(s_state);
    s_state->score = 0;
    sfText_setString(s_display->score1.text_score_int, "0");
    s_display->duck1.posx = 0;
    s_display->duck1.posy = rand() % 700;
    s_display->duck1.speed = 200;
    sfText_setPosition(s_display->score1.text_score_int,
    (sfVector2f){1800, 5});
    sfClock_restart(s_display->duck1.clock_anim);
    sfClock_restart(s_display->duck1.clock_pos);
    s_display->lives1.lives = 5;
    s_state->my_state = 1;
    restart_side(s_display);
}

void restart_side(sprites_s *s_display)
{
    s_display->side1.posx = rand() % 1000;
    s_display->side1.posy = 1080;
    s_display->side1.speed = 200;
    sfClock_restart(s_display->side1.clock_anim);
    sfClock_restart(s_display->side1.clock_pos);
}