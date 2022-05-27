/*
** EPITECH PROJECT, 2022
** asm
** File description:
** check_header
*/

#include "op.h"

int check_error_on_order(char **splitted, header_t *header, int line)
{
    if (*header->prog_name == 0 && !check_name(splitted[0]))
        return return_puterr(".name should be the first instruction: ",
        EXIT_ERROR, line);
    if (*header->prog_name != 0 && *header->comment == 0
    && !check_comment(splitted[0]))
        return return_puterr(".comment should be the second instruction: ",
        EXIT_ERROR, line);
    if (*header->prog_name != 0 && check_name(splitted[0]))
        return return_puterr("name already declared: ", EXIT_ERROR, line);
    if (*header->comment != 0 && check_comment(splitted[0]))
        return return_puterr("comment already declared: ", EXIT_ERROR, line);
    return 0;
}

int check_header_info(char **splitted,
header_t *head, int line_nbr, char *line)
{
    if (check_name(splitted[0]))
        return get_name(line, head, line_nbr, TRUE);
    if (check_comment(splitted[0]))
        return get_comment(line, head, line_nbr, TRUE);
    return 0;
}
