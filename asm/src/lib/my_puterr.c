/*
** EPITECH PROJECT, 2022
** asm
** File description:
** my_puterr
*/

#include "op.h"

void my_puterr(char *str)
{
    write(2, str, my_boostlen(str));
}
