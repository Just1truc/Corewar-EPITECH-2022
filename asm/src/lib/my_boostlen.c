/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** my_boostlen
*/

#include "op.h"

int my_boostlen(char *str)
{
    return ((*str) ? 1 + my_boostlen(&str[1]) : 0);
}

int my_tablen(char **str)
{
    int i;
    for (i = 0; str[i]; i++);
    return i;
}
