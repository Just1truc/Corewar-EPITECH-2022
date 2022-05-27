/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return_free
*/

#include "header.h"

int free_int(int *array)
{
    free(array);
    return 0;
}
