/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_list
*/

#include "op.h"

char **get_list(line_t **label_list)
{
    int i;
    char **result = malloc(sizeof(char *) * (my_listlen(label_list) + 1));

    for (i = 0; label_list[i]; i++) {
        result[i] = my_strdup(label_list[i]->str);
        result[i + 1] = NULL;
    }
    return result;
}
