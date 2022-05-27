/*
** EPITECH PROJECT, 2022
** asm
** File description:
** my_listlen
*/

#include "op.h"

int my_listlen(line_t **file)
{
    int i = 0;
    for (; file[i]; i++);
    return i;
}
