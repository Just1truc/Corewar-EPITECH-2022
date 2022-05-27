/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_strncpy
*/

#include "header.h"

char *my_strncpy(char *src, char *dest, int n)
{
    int i;

    for (i = 0; i < n; dest[i] = src[i], i++);
    dest[i] = 0;
    return dest;
}
