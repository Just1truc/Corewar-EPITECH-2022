/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** my_strdup
*/

#include "header.h"

char *my_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int i = 0; i < my_strlen(src) + 1; dest[i++] = 0);
    my_strncpy(src, dest, my_strlen(src));
    return dest;
}

char *my_strndup(char *src, int size)
{
    char *dest;

    dest = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size + 1; dest[i++] = 0);
    my_strncpy(src, dest, size);
    return dest;
}
