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

typedef struct timer {
    sfFont *font_score_txt;
    sfText *text_score_txt;
    sfFont *font_score_int;
    sfText *text_score_int;
    sfClock *timer_clock;
    sfTime *timer_time;
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
} sprites_s;

void manage_mouse_click(sfMouseButtonEvent, sfRenderWindow *);
void analyse_event(sfRenderWindow*, sfEvent, state*, sprites_s*);
int render_window(sfRenderWindow*, sfEvent, sfVideoMode);
void permanent_displays(sfRenderWindow*, state*, sprites_s*, sfIntRect*);
int load_sprite(sfRenderWindow*, sprites_s*, sfIntRect);
void move_rect(sfIntRect *, int, int);
void move_duck(sprites_s*);
int render_duck(sprites_s*, sfIntRect*, sfVideoMode);
int render_background(sfRenderWindow*, sprites_s*, sfVideoMode);
void render_all(sfRenderWindow*, sprites_s*, sfVideoMode, sfIntRect*);
int render_score_txt(sprites_s*);
int render_score_int(sprites_s*, state*);
void load_clocks(sprites_s*);
int my_strlen(char const *str);
char *my_revstr(char *str);
char const *my_put_strnbr(int n);

#endif