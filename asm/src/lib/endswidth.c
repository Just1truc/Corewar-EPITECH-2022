/*
** EPITECH PROJECT, 2022
** asm
** File description:
** endswidth
*/

#include "op.h"

int endswidth(char *str, char *end)
{
    int len_str = my_boostlen(str) - 1;
    int len_end = my_boostlen(end) - 1;

    for (; len_end >= 0 && len_str >= 0 && str[len_str]
    == end[len_end]; len_str--, len_end--);
    if (len_end == -1)
        return TRUE;
    else
        return FALSE;
}
