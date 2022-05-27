/*
** EPITECH PROJECT, 2022
** asm
** File description:
** check_args
*/

#include "op.h"

int check_register(char *str)
{
    return (str[0] == 'r' && my_boostlen(str) >= 2
    && check_string(&str[1], "0123456789")
    && getnbr(&str[1]) >= 1 && getnbr(&str[1]) <= REG_NUMBER);
}

int check_direct(char *str, char **labels)
{
    return (str[0] == DIRECT_CHAR && my_boostlen(str) >= 2 &&
    ((str[1] == LABEL_CHAR && is_in_list(&str[2], labels))
    || (check_string(&str[1], "0123456789")) || (check_nbr(&str[1]))));
}

int check_indirect(char *str, char **labels)
{
    return (str[0] == LABEL_CHAR && is_in_list(&str[1], labels))
    || (check_string(str, "0123456789")) || (check_nbr(str));
}
