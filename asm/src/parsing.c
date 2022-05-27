/*
** EPITECH PROJECT, 2022
** asm
** File description:
** my_function
*/

#include "op.h"

int parser(char *filename)
{
    int fd __attribute__((__cleanup__(cleanup_close))) = 0;
    char *file_content;
    char **lines;
    char test[10];
    line_t **tmp;

    if ((fd = open(filename, O_RDONLY)) <= 0) {
        my_puterr(NO_FILE_ERROR);
        exit(EXIT_ERROR);
    } else if (read(fd, test, 9) <= 0)
        return return_puterr("Empty file: ", 84, 0);
    file_content = get_file(filename);
    lines = my_split(file_content, "\n");
    free(file_content);
    tmp = clean_tab(lines);
    free_tab(lines);
    check_error(tmp);
    filename[my_boostlen(filename) - 2] = 0;
    encrypt(tmp, filename);
    return 0;
}
