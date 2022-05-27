/*
** EPITECH PROJECT, 2022
** asm
** File description:
** clean_tab
*/

#include "op.h"

char *my_strdup_wt_comments(char *str)
{
    char *copy = malloc(sizeof(char) * (my_boostlen(str) + 1));
    int i;

    for (i = 0; str[i] && str[i] != COMMENT_CHAR; copy[i] = str[i], i++);
    copy[i] = 0;
    return copy;
}

line_t **clean_tab(char **lines)
{
    line_t **result = malloc(sizeof(line_t *) * (my_tablen(lines) + 1));
    int u = 0;
    char **splitted_line;

    for (int i = 0; lines[i]; i++) {
        splitted_line = my_split(lines[i], (char *)separators);
        if (splitted_line[0][0] != COMMENT_CHAR
        && !check_string(lines[i], " \t#")) {
            result[u] = malloc(sizeof(line_t));
            result[u]->str = my_strdup_wt_comments(lines[i]);
            result[u++]->line = i;
        }
        free_tab(splitted_line);
    }
    result[u] = NULL;
    return result;
}
