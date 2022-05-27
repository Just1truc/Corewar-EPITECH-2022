/*
** EPITECH PROJECT, 2022
** asm
** File description:
** free_maps
*/

#include "op.h"

int free_tab(char **tab)
{
    for (int i = 0; tab[i]; free(tab[i++]));
    free(tab);
    return 0;
}
