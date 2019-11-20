/*
** EPITECH PROJECT, 2019
** score
** File description:
** write score in file
*/

#include "../include/my.h"

int get_score(void)
{
    int fd = open("scores.txt", O_RDWR);
    int best = 0;
    char c;

    for (; read(fd, &c, 1) == 1 && c != ';';)
        best = best * 10 + (c - 48);
    close(fd);
    return (best);
}

void write_score(state *s_state)
{
    int size = my_strlen(s_state->str_score);
    int best = get_score();
    int fd = open("scores.txt", O_RDWR);

    if (s_state->score > best) {
        write(fd, s_state->str_score, size);
        write(fd, ";", 1);
    }
    close(fd);
}