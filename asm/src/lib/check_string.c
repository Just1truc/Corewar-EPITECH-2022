/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** check_string
*/

#include "op.h"

int check_string(char *str, char *auth)
{
    int u;
    for (int i = 0; str[i]; i++) {
        for (u = 0; auth[u] && auth[u] != str[i]; u++);
        if (!auth[u])
            return FALSE;
    }
    return TRUE;
}
