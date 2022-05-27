/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** my_strcmp
*/

#include "op.h"

int my_strcmp(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i] && str2[i] == str1[i]; i++);
    return str1[i] - str2[i];
}
