/*
** EPITECH PROJECT, 2022
** asm
** File description:
** calcul_line_cost
*/

#include "op.h"

static const char *indexs[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lfork",
    "lldi",
    NULL
};

int get_bytes_nbr(int *array, char *command_name)
{
    int i;
    int index = is_in_list(command_name, (char **)indexs);
    int nbr = 0;

    for (i = 0; array[i]; i++)
        nbr += (!index) ? sizes[array[i]] : index_sizes[array[i]];
    return nbr;
}

int calcul_cost(char *line, char **labels)
{
    char **splitted;
    int i;
    int *array;
    splitted = my_split(line, (char *)separators);
    if (my_tablen(splitted) == 1)
        return free_tab(splitted);
    if (check_label(splitted[0]) && check_command(splitted[1])) {
        for (i = 0; my_strcmp(op_tab[i].mnemonique, splitted[1]) != 0; i++);
        array = get_params(&splitted[2], labels);
        return op_tab[i].weight + get_bytes_nbr(array, splitted[1])
        + 1 - return_freeint(array) - free_tab(splitted);
    }
    if (check_command(splitted[0])) {
        for (i = 0; my_strcmp(op_tab[i].mnemonique, splitted[0]) != 0; i++);
        array = get_params(&splitted[1], labels);
        return op_tab[i].weight + get_bytes_nbr(array, splitted[0])
        + 1 - return_freeint(array) - free_tab(splitted);
    }
    return free_tab(splitted);
}
