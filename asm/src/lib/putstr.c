/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** putstr
*/

#include "op.h"

void my_putstr(char *s)
{
    int i = -1;

    if (!s)
        return;
    while (s[++i])
        write(1, &s[i], 1);
}
