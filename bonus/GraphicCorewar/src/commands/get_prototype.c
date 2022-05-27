/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_prototype
*/

#include "header.h"

int *get_prototype(int proto)
{
    int *array = malloc(sizeof(int) * 5);
    int i;

    for (i = 0; i < 4; i++) {
        array[i] = ((proto >> 6) & 1) + ((((proto >> 6) >> 1) & 1) << 1);
        proto <<= 2;
    }
    array[i] = 0;
    return array;
}
