/*
** EPITECH PROJECT, 2022
** asm
** File description:
** main_checker
*/

#include "op.h"

int check_line(char *line, header_t *head, int line_nbr, char **labels)
{
    char **splitted;
    splitted = my_split(line, (char *)separators);
    if (check_exist(splitted[0], line_nbr) == EXIT_ERROR)
        return EXIT_ERROR - free_tab(splitted);
    if (check_error_on_order(splitted, head, line_nbr) == EXIT_ERROR)
        return EXIT_ERROR - free_tab(splitted);
    if (check_header_info(splitted, head, line_nbr, line) == EXIT_ERROR)
        return EXIT_ERROR - free_tab(splitted);
    if (check_label(splitted[0]) && splitted[1] && check_command(splitted[1]))
        return check_params(&splitted[2], splitted[1], line_nbr, labels)
        - free_tab(splitted);
    else if (check_label(splitted[0]) && splitted[1]
    && !check_command(splitted[1]))
        return return_puterr("Unknown command: ", 84, line_nbr)
        - free_tab(splitted);
    if (check_command(splitted[0]))
        return check_params(&splitted[1], splitted[0], line_nbr, labels)
        - free_tab(splitted);
    free_tab(splitted);
    return 0;
}

static void free_exit_in_enc(line_t **tab)
{
    if (tab)
        free_line_struct(tab);
    exit(EXIT_ERROR);
}

void check_error(line_t **file)
{
    int i;
    header_t header = {0};
    char **labels = get_labels(file);
    header.magic = COREWAR_EXEC_MAGIC;

    for (i = 0; file[i]; i++) {
        if (check_line(file[i]->str, &header,
        file[i]->line + 1, labels) == EXIT_ERROR)
            free_exit_in_enc(file - free_tab(labels));
    }
    free_tab(labels);
}
