/*
** EPITECH PROJECT, 2022
** asm
** File description:
** return_puterr
*/

#include "op.h"

int return_puterr(char *str, int return_value, int line)
{
    my_puterr(str);
    my_putnbr(line);
    my_puterr("\n");
    return return_value;
}
