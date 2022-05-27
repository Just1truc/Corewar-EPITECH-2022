/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** my_strcat
*/

#include "op.h"

char *my_strcat(char *s1, char *s2)
{
    char *r = malloc(sizeof(char) * (my_boostlen(s1) + my_boostlen(s2) + 1));
    int i;
    int u;
    for (i = 0; s1[i]; r[i] = s1[i], i++);
    for (u = i; s2[i - u]; r[i] = s2[i - u], i++);
    r[i] = 0;
    return r;
}
