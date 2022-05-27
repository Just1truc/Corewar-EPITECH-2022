/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_labels
*/

#include "op.h"

int count_labels(line_t **lines)
{
    int nbr = 0;
    char **splitted;

    for (int i = 0; lines[i]; i++) {
        splitted = my_split(lines[i]->str, (char *)separators);
        if (check_label(splitted[0]) - free_tab(splitted))
            nbr++;
    }
    return nbr;
}

char **get_labels(line_t **file)
{
    char **labels = malloc(sizeof(char *) * (count_labels(file) + 1));
    char **splitted;
    char *tmp;
    int u = 0;
    labels[0] = NULL;
    for (int i = 0; file[i]; i++) {
        splitted = my_split(file[i]->str, (char *)separators);
        if (check_label(splitted[0]) &&
        (tmp = delete_char(my_strdup(splitted[0]), LABEL_CHAR))
        && (is_in_list(tmp, labels) - return_free(tmp)))
            exit(return_puterr("Double declaration of label: ",
            84 - free_tab(splitted) -
            free_tab(labels), file[i]->line) - free_line_struct(file));
        if (check_label(splitted[0])) {
            labels[u++] = delete_char(my_strdup(splitted[0]), LABEL_CHAR);
            labels[u] = NULL;
        }
        free_tab(splitted);
    }
    return labels;
}
