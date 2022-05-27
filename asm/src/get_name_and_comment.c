/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_name_and_comment
*/

#include "op.h"

int get_name(char *line, header_t *header, int line_nbr, int boole)
{
    int i = my_boostlen(NAME_CMD_STRING);
    int u;
    int end;

    for (u = 0; line[u] && is_one_of(line[u], " \t"); u++);
    u += i;
    for (; line[u] && is_one_of(line[u], " \t"); u++);
    if (line[u] != '"')
        return return_puterr("Not well formated Name: ", EXIT_ERROR, line_nbr);
    for (end = my_boostlen(line) - 1; end >= 0
    && is_one_of(line[end], " \t"); end--);
    if (line[end] != '"' || end == u || end - u - 2 >= PROG_NAME_LENGTH)
        return return_puterr("Not well formated Name: ", EXIT_ERROR, line_nbr);
    if (boole)
        header->prog_name[0] = 1;
    else {
        line[end] = 0;
        my_strcpy(&line[u + 1], header->prog_name);
    }
    return 0;
}

int get_comment(char *line, header_t *header, int line_nbr, int boole)
{
    int i = my_boostlen(COMMENT_CMD_STRING);
    int u;
    int end;
    for (u = 0; line[u] && is_one_of(line[u], " \t"); u++);
    for (u += i; line[u] && is_one_of(line[u], " \t"); u++);
    if (line[u] != '"')
        return return_puterr("Not well formated comment: ",
        EXIT_ERROR, line_nbr);
    for (end = my_boostlen(line) - 1; end >= 0
    && is_one_of(line[end], " \t"); end--);
    if (line[end] != '"' || end == u || end - u - 2 >= COMMENT_LENGTH)
        return return_puterr("Not well formated comment: ",
        EXIT_ERROR, line_nbr);
    if (boole)
        header->comment[0] = 1;
    else {
        line[end] = 0;
        my_strcpy(&line[u + 1], header->comment);
    }
    return 0;
}
