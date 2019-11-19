/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** start
*/

#include "../include/my.h"

void destroy_all(sfRenderWindow *window, sprites_s *s_display, state *s_state)
{
    free(s_display->timer1.strtime), free(s_state->str_score);
    sfSprite_destroy(s_display->duck1.duck_sprt);
    sfSprite_destroy(s_display->background1.background_sprt);
    sfTexture_destroy(s_display->duck1.duck_txt);
    sfTexture_destroy(s_display->background1.background_txt);
    sfFont_destroy(s_display->score1.font_score_int);
    sfFont_destroy(s_display->score1.font_score_txt);
    sfFont_destroy(s_display->timer1.font_timer);
    sfFont_destroy(s_display->g_over.over_font);
    sfFont_destroy(s_display->g_over.your_font);
    sfText_destroy(s_display->score1.text_score_int);
    sfText_destroy(s_display->score1.text_score_txt);
    sfText_destroy(s_display->timer1.text_timer);
    sfText_destroy(s_display->g_over.over_txt);
    sfText_destroy(s_display->g_over.your_text);
    sfClock_destroy(s_display->duck1.clock_anim);
    sfClock_destroy(s_display->duck1.clock_pos);
    sfClock_destroy(s_display->timer1.timer_clock);
    sfRenderWindow_destroy(window);
}

void render_all(sfRenderWindow *window, sprites_s *s_display, sfIntRect *rect)
{
    render_background(window, s_display);
    render_duck(s_display, rect);
    render_score_txt(s_display);
    render_timer_int(s_display);
    render_game_over(s_display);
    render_your_score(s_display);
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
    s_state.my_state = 1, s_display.duck1.speed = 500;
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
    destroy_all(window, &s_display, &s_state);
    return (0);
}

int main(void)
{
    sfRenderWindow* window;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "DUCK", sfResize | sfClose, NULL);
    render_window(window, event);
    return (EXIT_SUCCESS);
}