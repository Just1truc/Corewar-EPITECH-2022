/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_strncat
*/

#include "header.h"

char *my_strncat(char *str1, char *str2, int n1, int n2)
{
    char *str = malloc(sizeof(char) * (n1 + n2 + 1));
    int i;
    int u;

    for (i = 0; i < n1; i++) {
        str[i] = str1[i];
    }
    for (u = 0; u < n2; u++, i++) {
        str[i] = str2[u];
    }
    str[i] = 0;
    return str;
}
