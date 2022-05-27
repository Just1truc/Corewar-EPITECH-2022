/*
** EPITECH PROJECT, 2022
** asm
** File description:
** calcul_prototype
*/

#include "op.h"

char get_prototype(int *array)
{
    char c = 0;
    int i;

    for (i = 0; i < 4; i++) {
        c <<= 2;
        c += (i < my_arraylen(array)) ? binary[array[i]] : 0;
    }
    return c - return_freeint(array);
}
