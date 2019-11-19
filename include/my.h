/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "time.h"

typedef struct duck {
    sfSprite* duck_sprt;
    sfTexture* duck_txt;
    sfClock *clock_anim;
    sfClock *clock_pos;
    sfTime time_anim;
    sfTime time_pos;
    float posx;
    float posy;
    float seconds_anim;
    float seconds_pos;
    int speed;
} duck_s;

typedef struct score {
    sfFont *font_score_txt;
    sfText *text_score_txt;
    sfFont *font_score_int;
    sfText *text_score_int;
} score;

typedef struct game_over {
    sfFont *over_font;
    sfText *over_txt;
    sfFont *your_font;
    sfText *your_text;
    sfFont *restart_font;
    sfText *restart_txt;
} game_over;

typedef struct timer {
    sfFont *font_timer;
    sfText *text_timer;
    int time;
    char *strtime;
    sfClock *timer_clock;
    sfTime timer_time;
    float seconds_timer;
} timer;

typedef struct background {
    sfTexture* background_txt;
    sfSprite* background_sprt;
} background_s;

typedef struct state {
    int my_state;
    float mouse_posx;
    float mouse_posy;
    int score;
    char *str_score;
} state;

typedef struct sprites {
    duck_s duck1;
    background_s background1;
    score score1;
    timer timer1;
    game_over g_over;
} sprites_s;

void analyse_event(sfRenderWindow*, sfEvent, state*, sprites_s*);
void manage_mouse_click(sfMouseButtonEvent, sfRenderWindow*);
void move_rect(sfIntRect *, int, int);
void move_duck(sprites_s*);
void render_all(sfRenderWindow*, sprites_s*, sfIntRect*);
int render_window(sfRenderWindow*, sfEvent);
int render_duck(sprites_s*, sfIntRect*);
int render_background(sfRenderWindow*, sprites_s*);
int render_score_txt(sprites_s*);
int render_score_int(sprites_s*, state*);
int render_timer_int(sprites_s*);
int render_game_over(sprites_s*);
int render_restart(sprites_s*);
int render_your_score(sprites_s*);
void load_clocks(sprites_s*);
void load_sprite(sprites_s*, sfIntRect);
void permanent_displays(sfRenderWindow*, state*, sprites_s*, sfIntRect*);
void display_timer(sprites_s*, sfRenderWindow*, state*);
void display_score(sprites_s*, sfRenderWindow*);
void display_duck(sprites_s*, sfRenderWindow*, sfIntRect*);
void display_game_over(sprites_s*, sfRenderWindow*);
void destroy_all(sfRenderWindow*, sprites_s*, state*);
void destroy_next(sprites_s*);
int my_strlen(char *);
char *my_revstr(char *);
char *my_put_strnbr(int);
void write_score(state*);

#endif