/*
** EPITECH PROJECT, 2022
** asm
** File description:
** display_header
*/

#include "op.h"

void display_header(header_t *header, int fd)
{
    write(fd, header, sizeof(header_t));
}

int show_header(line_t **lines, int fd, char **labels)
{
    header_t header = {0};
    char **splitted;
    int nbr = 0;

    for (int i = 0; lines[i]; i++) {
        splitted = my_split(lines[i]->str, (char *)separators);
        if (check_name(splitted[0]))
            get_name(lines[i]->str, &header, lines[i]->line, FALSE);
        if (check_comment(splitted[0]))
            get_comment(lines[i]->str, &header, lines[i]->line, FALSE);
        nbr += calcul_cost(lines[i]->str, labels);
        free_tab(splitted);
    }
    header.prog_size = get_little_big(nbr);
    header.magic = get_little_big(COREWAR_EXEC_MAGIC);
    display_header(&header, fd);
    return 0;
}
