/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check_int_array
*/

#include "header.h"

int check_int_array(int *array, int *auth)
{
    int i;
    int u;

    for (i = 0; array[i]; i++) {
        for (u = 0; auth[u] && array[i] != auth[u]; u++);
        if (!auth[u])
            return FALSE;
    }
    return TRUE;
}
