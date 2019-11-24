/*
** EPITECH PROJECT, 2019
** Graphic
** File description:
** start
*/

#include "../include/my.h"

int message(void)
{
    write(1, "Welcome to the hunter game !\n\n", 30);
    write(1, "You can shoot the ducks with any mouse button click.\n", 53);
    write(1, "Your only have 5 lives.\n", 24);
    write(1, "Your lives are displayed on the top.\n", 37);
    write(1, "Ducks will come from left and bottom positions.\n", 48);
    write(1,
    "Your score will be saved at the end and displayed in the menu !\n\n", 65);
    write(1, "Good luck try your best and have fun !\n", 39);
    exit(EXIT_SUCCESS);
}

void render_all(sfRenderWindow *window, sprites_s *s_display)
{
    render_background(window, s_display), render_duck(s_display);
    render_score_txt(s_display), render_timer_int(s_display);
    render_game_over(s_display), render_your_score(s_display);
    render_restart(s_display), render_title(s_display);
    render_best_txt(s_display), render_best_int(s_display);
    render_start(s_display), render_dog(s_display);
    render_dead(s_display), render_falling(s_display);
    render_side_duck(s_display), render_duck(s_display);
    render_sound(s_display), render_crosshair(s_display);
}

void load_sprite_animation(sprites_s *s_display)
{
    load_clocks(s_display);
    move_dog(s_display);
    move_duck(s_display);
    move_falling(s_display);
    move_side_duck(s_display);
}

int render_window(sfRenderWindow* window, sfEvent event)
{
    state s_state;
    sprites_s s_display;
    s_state.my_state = 2;
    render_all(window, &s_display);
    render_score_int(&s_display, &s_state);
    if (!window)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, &s_state, &s_display);
        }
        load_sprite_animation(&s_display);
        permanent_displays(window, &s_state, &s_display);
    }
    write_score(&s_state);
    destroy_all(window, &s_display, &s_state);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        srand(time(NULL));
        sfRenderWindow* window;
        sfEvent event;
        sfVideoMode mode = {1920, 1080, 32};
        window = sfRenderWindow_create(mode, "DUCK", sfResize | sfClose, NULL);
        render_window(window, event);
    }
    else if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        message();
    else {
        write(2, "WRONG ARG", 9);
        exit(84);
    }
    return (EXIT_SUCCESS);
}