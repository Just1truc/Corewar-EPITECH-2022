/*
** EPITECH PROJECT, 2022
** asm
** File description:
** getnbr
*/

#include "op.h"

int getnbr(char *str)
{
    int neg = 1;
    int i;

    for (i = 0; str[i] && (str[i] == '-' || str[i] == '+');
    neg *= (str[i] == '-') ? -1 : 1, i++);
    return my_atoi(&str[i]) * neg;
}

int check_nbr(char *str)
{
    int i;

    for (i = 0; str[i] && (str[i] == '-' || str[i] == '+'); i++);
    if (!str[i])
        return 84;
    return check_string(&str[i], "0123456789");
}
