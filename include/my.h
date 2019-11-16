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
} duck_s;

typedef struct background {
    sfTexture* background_txt;
    sfSprite* background_sprt;
} background_s;

typedef struct state {
    int my_state;
} state;

typedef struct sprites {
    duck_s duck1;
    background_s background1;
} sprites_s;

void manage_mouse_click(sfMouseButtonEvent, sfRenderWindow *);
void analyse_event(sfRenderWindow*, sfEvent, state*);
int render_window(sfRenderWindow*, sfEvent, sfVideoMode);
void permanent_displays(sfRenderWindow*, state*, sprites_s*, sfIntRect*);
int load_sprite(sfRenderWindow*, sprites_s*, sfIntRect);
void move_rect(sfIntRect *, int, int);
void move_duck(sprites_s *s_display);
int render_duck(sprites_s*, sfIntRect*, sfVideoMode);
int render_background(sfRenderWindow*, sprites_s*, sfVideoMode);
void load_clocks(sprites_s *s_display);

#endif