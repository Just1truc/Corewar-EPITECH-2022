/*
** EPITECH PROJECT, 2022
** asm
** File description:
** main_encrypt
*/

#include "op.h"

void display_label_command(line_t **file, char **labels,
int *both, char **splitted)
{
    int i;
    int fd = both[0];
    int line_nbr = both[1];
    char c;

    for (i = 0; my_strcmp(op_tab[i].mnemonique, splitted[1]) != 0; i++);
    write(fd, &op_tab[i].code, sizeof(char));
    if (op_tab[i].weight) {
        c = get_prototype(get_params(&splitted[2], labels));
        write(fd, &c, sizeof(char));
    }
    display_encrypt(&splitted[2], file,
    splitted[1], (int[2]){fd, line_nbr});
}

void encrypt_line(line_t **file, char **labels, int line_nbr, int fd)
{
    char **splitted;
    char *lines = file[line_nbr]->str;
    char c;
    int i;
    splitted = my_split(lines, (char *)separators);
    if ((!splitted || my_tablen(splitted) == 1) && !free_tab(splitted))
        return;
    if (check_label(splitted[0]) && check_command(splitted[1]))
        display_label_command(file, labels, (int[2]){fd, line_nbr}, splitted);
    if (check_command(splitted[0])) {
        for (i = 0; my_strcmp(op_tab[i].mnemonique, splitted[0]) != 0; i++);
        write(fd, &op_tab[i].code, sizeof(char));
        if (op_tab[i].weight) {
            c = get_prototype(get_params(&splitted[1], labels));
            write(fd, &c, sizeof(char));
        }
        display_encrypt(&splitted[1],
        file, splitted[0], (int[2]){fd, line_nbr});
    }
    free_tab(splitted);
}

void encrypt(line_t **lines, char *file)
{
    char **splitted = my_split(file, "/");
    char *filename = my_strcat(splitted[my_tablen(splitted) - 1], ".cor");
    int fd = open(filename,
    O_TRUNC | O_WRONLY | O_CREAT | O_APPEND, 0644) - return_free(filename);
    char **labels = get_labels(lines);
    int i;

    show_header(lines, fd, labels);
    for (i = 0; lines[i]; i++) {
        encrypt_line(lines, labels, i, fd);
    }
    free_tab(splitted);
    close(fd);
    free_tab(labels);
    free_line_struct(lines);
}
