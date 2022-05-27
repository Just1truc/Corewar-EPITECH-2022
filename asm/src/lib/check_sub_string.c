/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** check_sub_string
*/

#include "op.h"

int check_sub(char *string, char *sub)
{
    int i;
    int u;
    for (i = 0; string[i]; i++) {
        for (u = 0; sub[u] && string[i] && sub[u] == string[i]; u++, i++);
        if (!sub[u])
            return TRUE;
    }
    return FALSE;
}
