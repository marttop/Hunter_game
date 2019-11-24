/*
** EPITECH PROJECT, 2019
** side_duck
** File description:
** side_duck
*/

#include "../include/my.h"

int render_side_duck(sprites_s *s_display)
{
    s_display->side1.clock_anim = sfClock_create();
    s_display->side1.clock_pos = sfClock_create();
    s_display->side1.rect_duck.left = 0;
    s_display->side1.rect_duck.top = 0;
    s_display->side1.rect_duck.width = 110;
    s_display->side1.rect_duck.height = 110;
    s_display->side1.speed = 100;
    s_display->side1.duck_txt =
    sfTexture_createFromFile("sprites/Flying.png", NULL);
    if (!s_display->side1.duck_txt)
        return (EXIT_FAILURE);
    s_display->side1.duck_sprt = sfSprite_create();
    sfSprite_setTexture(s_display->side1.duck_sprt,
    s_display->side1.duck_txt, sfTrue);
    s_display->side1.posx = 0, s_display->side1.posy = 1080;
    sfSprite_setPosition(s_display->side1.duck_sprt,
    (sfVector2f){s_display->side1.posx, s_display->side1.posy});
    return (0);
}

void move_rect_side_duck(sprites_s *s_display, int offset, int max_value)
{
    if (s_display->side1.rect_duck.left < max_value - offset) {
        s_display->side1.rect_duck.left += offset;
    }
    else
        s_display->side1.rect_duck.left = 0;
}

void move_side_duck(sprites_s *s_display)
{
    if (s_display->side1.posx < 1920 && s_display->side1.posy > -100) {
        s_display->side1.posx += s_display->side1.speed *
        s_display->side1.seconds_pos;
        s_display->side1.posy -= s_display->side1.speed *
        s_display->side1.seconds_pos;
    }
    else {
        s_display->side1.posx = rand() % 1000;
        s_display->side1.posy = 1080;
        s_display->lives1.lives -= 1;
        s_display->lives1.strlives = my_put_strnbr(s_display->lives1.lives);
    }
    sfClock_restart(s_display->side1.clock_pos);
}

void display_side(sprites_s *s_display, sfRenderWindow *window, state *s_state)
{
    sfSprite_setPosition(s_display->side1.duck_sprt,
    (sfVector2f){s_display->side1.posx, s_display->side1.posy});
    sfSprite_setTextureRect(s_display->side1.duck_sprt,
    s_display->side1.rect_duck);
    if (s_display->side1.seconds_anim > 0.1) {
        move_rect_side_duck(s_display, 110, 330);
        sfClock_restart(s_display->side1.clock_anim);
    }
    sfRenderWindow_drawSprite(window, s_display->side1.duck_sprt, NULL);
    display_dead_side(window, s_state, s_display);
}

void check_hitbox_side(sprites_s *s_display, sfRenderWindow *window,
                        state *s_state)
{
    s_state->mouse_posx = sfMouse_getPositionRenderWindow(window).x;
    s_state->mouse_posy = sfMouse_getPositionRenderWindow(window).y;
    if ((s_state->mouse_posx > s_display->side1.posx &&
    s_state->mouse_posx < s_display->side1.posx + 110) &&
    s_state->mouse_posy > s_display->side1.posy &&
    s_state->mouse_posy < s_display->side1.posy + 110) {
        if (s_state->str_score != NULL)
            free(s_state->str_score);
        s_state->score += 1;
        s_state->str_score = my_put_strnbr(s_state->score);
        draw_dead_side(s_display, s_state);
        s_display->side1.posx = rand() % 1000;
        s_display->side1.posy = 1080, s_display->side1.speed += 35;
        sfMusic_stop(s_display->sounds1.hit);
        sfMusic_play(s_display->sounds1.hit);
        sfText_setString(s_display->score1.text_score_int, s_state->str_score);
        sfText_setFont(s_display->score1.text_score_int,
        s_display->score1.font_score_int);
    }
}