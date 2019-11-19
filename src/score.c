/*
** EPITECH PROJECT, 2019
** score
** File description:
** write score in file
*/

#include "../include/my.h"

void write_score(state *s_state)
{
    char c;
    int size = my_strlen(s_state->str_score);
    int fd = open("scores.txt", O_RDWR);
    while (read(fd, &c, 1) == 1);
    write(fd, s_state->str_score, size);
    while (read(fd, &c, 1) == 1);
    write(fd, ";", 1);
}