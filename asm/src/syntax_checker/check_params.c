/*
** EPITECH PROJECT, 2022
** asm
** File description:
** check_params
*/

#include "op.h"

int *get_params(char **args, char **labels)
{
    int *array = malloc(sizeof(int) * 5);
    int i;

    for (i = 0; args[i]; i++) {
        array[i] = 84;
        if (check_register(args[i]))
            array[i] = T_REG;
        if (check_direct(args[i], labels))
            array[i] = T_DIR;
        if (check_indirect(args[i], labels))
            array[i] = T_IND;
        if (array[i] == 84) {
            free(array);
            return NULL;
        }
    }
    array[i] = 0;
    return array;
}

int my_arraylen(int *array)
{
    int i;
    for (i = 0; array[i]; i++);
    return i;
}

int check_params(char **args, char *command_name, int line_nbr, char **labels)
{
    int *array;
    int i;
    int u;
    if (!args)
        return 84;
    array = get_params(args, labels);
    if (!array)
        return return_puterr("Bad argument: ", 84, line_nbr)
        - return_freeint(array);
    for (i = 0; op_tab[i].mnemonique
    && my_strcmp(op_tab[i].mnemonique, command_name); i++);
    if (my_arraylen(array) != op_tab[i].nbr_args)
        return return_puterr("Bad number of arguments: ", 84, line_nbr)
        - return_freeint(array);
    for (u = 0; u < op_tab[i].nbr_args
    && ((op_tab[i].type[u] & array[u]) == array[u]); u++);
    if (u != op_tab[i].nbr_args)
        return return_puterr("Bad Arguments Types: ", 84, line_nbr)
        - return_freeint(array);
    return return_freeint(array);
}
