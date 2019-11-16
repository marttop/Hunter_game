/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** start
*/

#include "../include/my.h"

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
    s_state.my_state = 1;
    s_display.duck1.posx = 0, s_display.duck1.posy = 50;
    window = sfRenderWindow_create(mode, "DUCK", sfResize | sfClose, NULL);
    render_background(window, &s_display, mode);
    render_duck(&s_display, &rect, mode);
    if (!window)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, &s_state);
        }
        load_sprite(window, &s_display, rect);
        permanent_displays(window, &s_state, &s_display, &rect);
    }
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