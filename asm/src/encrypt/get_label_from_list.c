/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_label_from_list
*/

#include "op.h"

line_t **get_label_list(line_t **file)
{
    line_t **labels = malloc(sizeof(line_t *) * (count_labels(file) + 1));
    char **splitted;
    int u = 0;
    labels[0] = NULL;
    for (int i = 0; file[i]; i++) {
        splitted = my_split(file[i]->str, (char *)separators);
        if (check_label(splitted[0])) {
            labels[u] = malloc(sizeof(line_t));
            labels[u]->str = delete_char(my_strdup(splitted[0]), LABEL_CHAR);
            labels[u++]->line = file[i]->line;
            labels[u] = NULL;
        }
        free_tab(splitted);
    }
    return labels;
}
