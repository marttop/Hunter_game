/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "../include/my.h"

int render_title(sprites_s *s_display)
{
    s_display->menu1.title_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->menu1.title_font)
        return (EXIT_FAILURE);
    s_display->menu1.title_txt = sfText_create();
    sfText_setString(s_display->menu1.title_txt, "MY HUNTER");
    sfText_setFont(s_display->menu1.title_txt, s_display->menu1.title_font);
    sfText_setCharacterSize(s_display->menu1.title_txt, 100);
    sfText_setPosition(s_display->menu1.title_txt, (sfVector2f){620, 60});
    return (0);
}

int render_best_txt(sprites_s *s_display)
{
    s_display->menu1.best_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->menu1.best_font)
        return (EXIT_FAILURE);
    s_display->menu1.best_txt = sfText_create();
    sfText_setString(s_display->menu1.best_txt, "The score to beat is :");
    sfText_setFont(s_display->menu1.best_txt, s_display->menu1.best_font);
    sfText_setCharacterSize(s_display->menu1.best_txt, 50);
    sfText_setPosition(s_display->menu1.best_txt, (sfVector2f){675, 200});
    return (0);
}

int render_best_int(sprites_s *s_display)
{
    s_display->menu1.strbest = my_put_strnbr(get_score());
    s_display->menu1.best_font_int = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->menu1.best_font_int)
        return (EXIT_FAILURE);
    s_display->menu1.best_txt_int = sfText_create();
    sfText_setString(s_display->menu1.best_txt_int, s_display->menu1.strbest);
    sfText_setFont(s_display->menu1.best_txt_int,
    s_display->menu1.best_font_int);
    sfText_setCharacterSize(s_display->menu1.best_txt_int, 150);
    sfText_setPosition(s_display->menu1.best_txt_int, (sfVector2f){900, 300});
    free(s_display->menu1.strbest);    
    return (0);
}

int render_start(sprites_s *s_display)
{
    s_display->menu1.start_font = sfFont_createFromFile("fonts/font.ttf");
    if (!s_display->menu1.start_font)
        return (EXIT_FAILURE);
    s_display->menu1.start_txt = sfText_create();
    sfText_setString(s_display->menu1.start_txt, "Press SPACE to start");
    sfText_setFont(s_display->menu1.start_txt, s_display->menu1.start_font);
    sfText_setCharacterSize(s_display->menu1.start_txt, 50);
    sfText_setPosition(s_display->menu1.start_txt, (sfVector2f){650, 900});
    return (0);
}

int render_dog(sprites_s *s_display)
{
    s_display->dog1.clock_anim = sfClock_create();
    s_display->dog1.clock_pos = sfClock_create();
    s_display->dog1.rect_dog.left = 0, s_display->dog1.rect_dog.top = 0;
    s_display->dog1.rect_dog.width = 130;
    s_display->dog1.rect_dog.height = 100;
    s_display->dog1.dog_txt =
    sfTexture_createFromFile("sprites/dog.png", NULL);
    if (!s_display->dog1.dog_txt)
        return (EXIT_FAILURE);
    s_display->dog1.dog_sprt = sfSprite_create();
    sfSprite_setTexture(s_display->dog1.dog_sprt,
    s_display->dog1.dog_txt, sfTrue);
    s_display->dog1.posx = 650, s_display->dog1.posy = 830;
    sfSprite_setPosition(s_display->dog1.dog_sprt, (sfVector2f){650, 830});
    return (0);
}