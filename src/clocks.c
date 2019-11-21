/*
** EPITECH PROJECT, 2019
** clocks
** File description:
** clocks
*/

#include "../include/my.h"

void load_clocks(sprites_s *s_display)
{
    s_display->duck1.time_anim =
    sfClock_getElapsedTime(s_display->duck1.clock_anim);
    s_display->duck1.time_pos =
    sfClock_getElapsedTime(s_display->duck1.clock_pos);
    s_display->timer1.timer_time =
    sfClock_getElapsedTime(s_display->timer1.timer_clock);
    s_display->duck1.seconds_anim =
    s_display->duck1.time_anim.microseconds / 1000000.0;
    s_display->duck1.seconds_pos =
    s_display->duck1.time_pos.microseconds / 1000000.0;
    s_display->timer1.seconds_timer =
    s_display->timer1.timer_time.microseconds / 1000000.0;
    load_next_clocks(s_display);
}

void load_next_clocks(sprites_s *s_display)
{
    s_display->dog1.time_anim =
    sfClock_getElapsedTime(s_display->dog1.clock_anim);
    s_display->dog1.time_pos =
    sfClock_getElapsedTime(s_display->dog1.clock_pos);
    s_display->dead1.time_pos =
    sfClock_getElapsedTime(s_display->dead1.clock_pos);
    s_display->dog1.seconds_anim =
    s_display->dog1.time_anim.microseconds / 1000000.0;
    s_display->dog1.seconds_pos =
    s_display->dog1.time_pos.microseconds / 1000000.0;
    s_display->dead1.seconds_pos =
    s_display->dead1.time_pos.microseconds / 1000000.0;
}