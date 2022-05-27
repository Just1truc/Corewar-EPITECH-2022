/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** my_strlen
*/

#include "header.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}

int my_arraylen(int *array)
{
    int i;
    for (i = 0; array[i]; i++);
    return i;
}
