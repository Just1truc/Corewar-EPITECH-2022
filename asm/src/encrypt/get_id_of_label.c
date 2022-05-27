/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_id_of_label
*/

#include "op.h"

int get_id_of_label(char *label, line_t **lines)
{
    int id;
    char **splitted;

    for (id = 0; lines[id]; id++) {
        splitted = my_split(lines[id]->str, (char *)separators);
        if (check_label(splitted[0])
        && my_strcmp(label, delete_char(splitted[0], LABEL_CHAR)) == 0)
            return id - free_tab(splitted);
        free_tab(splitted);
    }
    return 0;
}
