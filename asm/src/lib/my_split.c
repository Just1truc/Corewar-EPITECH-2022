/*
** EPITECH PROJECT, 2022
** solver
** File description:
** my_split
*/

#include "op.h"

int get_strlen(char *str)
{
    int i;
    for (i = 0; str[i++];);
    return i;
}

int get_len_of_word(char *str, int i, char *dels)
{
    int b;
    for (b = i; !is_one_of(str[i], dels)
    && str[i] != '\0'; i++);
    return i - b;
}

int is_one_of(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

char **my_split(char *str, char *dels)
{
    int i;
    int o = 0;
    int u = 0;
    char **result = malloc(sizeof(char *) * (get_strlen(str)));
    for (i = 0; str[i]; i++) {
        for (; (is_one_of(str[i], dels))
        && str[i] != '\0'; i++);
        result[o] = malloc(sizeof(char) *
        (get_len_of_word(str, i, dels) + 1));
        for (u = 0; (!is_one_of(str[i], dels))
        && str[i] != '\0'; result[o][u++] = str[i], i++);
        result[o++][u] = '\0';
        for (; (is_one_of(str[i], dels))
        && str[i] != '\0'; i++);
        i--;
    }
    result[o] = NULL;
    return result;
}
