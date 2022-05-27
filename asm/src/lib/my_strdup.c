/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** my_strdup
*/

#include "op.h"

char *my_strdup(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_boostlen(str) + 1));
    int i;
    for (i = 0; str[i]; str2[i] = str[i], i++);
    str2[i] = '\0';
    return str2;
}
