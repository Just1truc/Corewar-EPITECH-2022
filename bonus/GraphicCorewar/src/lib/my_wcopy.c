/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_wcopy
*/

#include "header.h"

char *my_wcopy(char *src, char *dest, int size, int depart)
{
    int i;
    int u = 0;

    for (i = get_mod(depart, MEM_SIZE); u < size;
    dest[u] = src[get_mod(i, MEM_SIZE)], i++, u++);
    return dest;
}
