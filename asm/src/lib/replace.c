/*
** EPITECH PROJECT, 2022
** asm
** File description:
** replace
*/

#include "op.h"

char *delete_char(char *str, char c)
{
    int val = 0;
    int i;

    for (i = 0; str[i + val]; i++) {
        if (str[i] == c) {
            str[i] = str[i + val + 1];
            i--;
            val++;
        }
    }
    str[i] = 0;
    return str;
}

char *replace(char *str, char c1, char c2)
{
    for (int i = 0; str[i]; str[i] = (str[i] == c1) ? c2 : c1, i++);
    return str;
}
