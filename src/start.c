/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** start
*/

#include "../include/my.h"

void render_all(sfRenderWindow *window, sprites_s *s_display, sfIntRect *rect)
{
    render_background(window, s_display);
    render_duck(s_display, rect);
    render_score_txt(s_display);
    render_timer_int(s_display);
    render_game_over(s_display);
    render_your_score(s_display);
    render_restart(s_display);
}

void load_sprite(sprites_s *s_display, sfIntRect rect)
{
    load_clocks(s_display);
    sfSprite_setTexture(s_display->duck1.duck_sprt,
    s_display->duck1.duck_txt, sfTrue);
    move_duck(s_display);
    sfSprite_setPosition(s_display->duck1.duck_sprt,
    (sfVector2f){s_display->duck1.posx, s_display->duck1.posy});
    sfSprite_setTextureRect(s_display->duck1.duck_sprt, rect);
}

int render_window(sfRenderWindow* window, sfEvent event)
{
    state s_state;
    sprites_s s_display;
    sfIntRect rect;
    s_state.my_state = 0, s_display.duck1.speed = 500;
    s_display.duck1.posx = 0, s_display.duck1.posy = 50;
    render_all(window, &s_display, &rect);
    render_score_int(&s_display, &s_state);
    if (!window)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, &s_state, &s_display);
        }
        load_sprite(&s_display, rect);
        permanent_displays(window, &s_state, &s_display, &rect);
    }
    write_score(&s_state);
    destroy_all(window, &s_display, &s_state);
    return (0);
}

int main(void)
{
    srand(time(NULL));
    sfRenderWindow* window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "DUCK", sfResize | sfClose, NULL);
    render_window(window, event);
    return (EXIT_SUCCESS);
}