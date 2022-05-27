/*
** EPITECH PROJECT, 2022
** asm
** File description:
** check_args_types
*/

#include "op.h"

int is_register(char *str)
{
    return (str[0] == 'r');
}

int is_direct(char *str)
{
    return (str[0] == DIRECT_CHAR);
}

int is_indirect(char *str)
{
    return (str[0] != 'r' && str[0] != DIRECT_CHAR);
}
