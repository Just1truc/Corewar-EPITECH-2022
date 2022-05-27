/*
** EPITECH PROJECT, 2022
** asm
** File description:
** is_in_list
*/

#include "op.h"

int is_in_list(char *str, char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0)
            return 1;
    }
    return 0;
}
