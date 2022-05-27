/*
** EPITECH PROJECT, 2022
** asm
** File description:
** return_free
*/

#include "op.h"

int return_free(char *str)
{
    free(str);
    return 0;
}
