/*
** EPITECH PROJECT, 2022
** asm
** File description:
** check_label
*/

#include "op.h"

int check_label(char *str)
{
    char *tmp = my_strdup(str);
    char test[] = {LABEL_CHAR, 0};

    return (endswidth(tmp, test) &&
    check_string(delete_char(tmp, LABEL_CHAR), LABEL_CHARS))
    - return_free(tmp);
}

int check_command(char *str)
{
    int i;

    for (i = 0; op_tab[i].code
    && my_strcmp(op_tab[i].mnemonique, str) != 0; i++);
    return (op_tab[i].code && my_strcmp(op_tab[i].mnemonique, str) == 0);
}

int check_comment(char *str)
{
    return (my_strcmp(str, COMMENT_CMD_STRING) == 0);
}

int check_name(char *str)
{
    return (my_strcmp(str, NAME_CMD_STRING) == 0);
}

int check_exist(char *str, int line)
{
    if (!check_comment(str) && !check_command(str)
    && !check_label(str) && !check_name(str))
        return return_puterr("Unknown command: ", EXIT_ERROR, line);
    return 0;
}
