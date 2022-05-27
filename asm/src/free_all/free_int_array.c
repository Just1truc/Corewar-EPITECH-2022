/*
** EPITECH PROJECT, 2022
** asm
** File description:
** free_int_array
*/

#include "op.h"

int return_freeint(int *array)
{
    free(array);
    return 0;
}
