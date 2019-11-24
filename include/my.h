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
    sfIntRect rect_duck;
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

typedef struct dead {
    sfSprite* dead_sprt;
    sfTexture* dead_txt;
    sfClock *clock_pos;
    sfTime time_pos;
    float seconds_pos;
} dead;

typedef struct falling {
    sfIntRect rect_duck;
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
} falling;

typedef struct side {
    sfIntRect rect_duck;
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
} side;

typedef struct dog {
    sfIntRect rect_dog;
    sfSprite *dog_sprt;
    sfTexture *dog_txt;
    sfClock *clock_anim;
    sfClock *clock_pos;
    sfTime time_anim;
    sfTime time_pos;
    float posx;
    float posy;
    float seconds_anim;
    float seconds_pos;
} dog;

typedef struct menu {
    sfText *title_txt;
    sfFont *title_font;
    sfText *best_txt_int;
    sfFont *best_font_int;
    sfText *best_txt;
    sfFont *best_font;
    sfText *start_txt;
    sfFont *start_font;
    int best;
    char *strbest;
} menu;

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

typedef struct lives {
    sfFont *font_lives;
    sfText *text_lives;
    int lives;
    char *strlives;
} lives;

typedef struct background {
    sfTexture* background_txt;
    sfSprite* background_sprt;
} background_s;

typedef struct state {
    int dead;
    int my_state;
    float mouse_posx;
    float mouse_posy;
    int score;
    char *str_score;
} state;

typedef struct sprites {
    duck_s duck1;
    dog dog1;
    background_s background1;
    score score1;
    lives lives1;
    game_over g_over;
    menu menu1;
    dead dead1;
    falling falling1;
    side side1;
} sprites_s;

void analyse_event(sfRenderWindow*, sfEvent, state*, sprites_s*);
void manage_mouse_click(sfMouseButtonEvent, sfRenderWindow*);
void check_hitbox(sprites_s*, sfRenderWindow*, state*);
void check_hitbox_side(sprites_s*, sfRenderWindow*, state*);
void restart(state*, sprites_s*);
void restart_side(sprites_s*);
void move_rect_duck(sprites_s*, int, int);
void move_rect_dog(sprites_s*, int, int);
void move_duck(sprites_s*);
void move_dog(sprites_s*);
void move_rect_falling(sprites_s*, int, int);
void move_rect_side_duck(sprites_s*, int, int);
void move_side_duck(sprites_s*);
void move_falling(sprites_s*);
void render_all(sfRenderWindow*, sprites_s*);
int render_window(sfRenderWindow*, sfEvent);
int render_duck(sprites_s*);
int render_dog(sprites_s*);
int render_background(sfRenderWindow*, sprites_s*);
int render_score_txt(sprites_s*);
int render_score_int(sprites_s*, state*);
int render_timer_int(sprites_s*);
int render_game_over(sprites_s*);
int render_restart(sprites_s*);
int render_your_score(sprites_s*);
int render_title(sprites_s*);
int render_best_txt(sprites_s*);
int render_best_int(sprites_s*);
int render_start(sprites_s*);
int render_dead(sprites_s*);
int render_falling(sprites_s*);
int render_side_duck(sprites_s*);
void draw_dead(sprites_s*, state*);
void draw_dead_side(sprites_s*, state*);
void load_clocks(sprites_s*);
void load_next_clocks(sprites_s*);
void load_second_clocks(sprites_s *);
void load_third_clocks(sprites_s*);
void load_sprite_animation(sprites_s*);
void permanent_displays(sfRenderWindow*, state*, sprites_s*);
void display_timer(sprites_s*, sfRenderWindow*, state*);
void display_score(sprites_s*, sfRenderWindow*);
void display_duck(sprites_s*, sfRenderWindow*, state*);
void display_game_over(sprites_s*, sfRenderWindow*);
void display_menu(sfRenderWindow*, sprites_s*);
void display_dog(sprites_s*, sfRenderWindow*);
void display_dead(sfRenderWindow*, state*, sprites_s*);
void display_dead_side(sfRenderWindow*, state*, sprites_s*);
void display_falling(sprites_s*, sfRenderWindow*);
void display_side(sprites_s*, sfRenderWindow*, state*);
void destroy_all(sfRenderWindow*, sprites_s*, state*);
void destroy_next(sprites_s*);
void destroy_second(sprites_s*);
int my_strlen(char *);
char *my_revstr(char *);
char *my_put_strnbr(int);
void write_score(state*);
int get_score(void);
int message(void);

#endif