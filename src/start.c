/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** start
*/

#include "../include/my.h"

void destroy_all(sfRenderWindow *window, sprites_s *s_display)
{
    sfSprite_destroy(s_display->duck1.duck_sprt);
    sfSprite_destroy(s_display->background1.background_sprt);
    sfTexture_destroy(s_display->duck1.duck_txt);
    sfTexture_destroy(s_display->background1.background_txt);
    sfFont_destroy(s_display->score1.font_score_int);
    sfFont_destroy(s_display->score1.font_score_txt);
    sfText_destroy(s_display->score1.text_score_int);
    sfText_destroy(s_display->score1.text_score_txt);
    sfClock_destroy(s_display->duck1.clock_anim);
    sfClock_destroy(s_display->duck1.clock_pos);
    sfRenderWindow_destroy(window);
}

void render_all(sfRenderWindow *window, sprites_s *s_display,
                sfVideoMode mode, sfIntRect *rect)
{
    render_background(window, s_display, mode);
    render_duck(s_display, rect, mode);
    render_score_txt(s_display);
}

int load_sprite(sfRenderWindow *window, sprites_s *s_display, sfIntRect rect)
{
    load_clocks(s_display);
    sfSprite_setTexture(s_display->duck1.duck_sprt,
    s_display->duck1.duck_txt, sfTrue);
    move_duck(s_display);
    sfSprite_setPosition(s_display->duck1.duck_sprt,
    (sfVector2f){s_display->duck1.posx, s_display->duck1.posy});
    sfSprite_setTextureRect(s_display->duck1.duck_sprt, rect);
}

int render_window(sfRenderWindow* window, sfEvent event, sfVideoMode mode)
{
    state s_state;
    sprites_s s_display;
    sfIntRect rect;
    s_state.my_state = 1, s_display.duck1.speed = 500;
    s_display.duck1.posx = 0, s_display.duck1.posy = 50;
    window = sfRenderWindow_create(mode, "DUCK", sfResize | sfClose, NULL);
    render_all(window, &s_display, mode, &rect);
    render_score_int(&s_display, &s_state);
    if (!window)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, &s_state, &s_display);
        }
        load_sprite(window, &s_display, rect);
        permanent_displays(window, &s_state, &s_display, &rect);
    }
    destroy_all(window, &s_display);
}

int main(void)
{
    sfRenderWindow* window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    render_window(window, event, mode);
    sfRenderWindow_destroy(window);
    return (0);
}