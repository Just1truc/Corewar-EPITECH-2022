/*
** EPITECH PROJECT, 2022
** asm
** File description:
** reader
*/

#include "op.h"

char *get_file(char *filename)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t size = 0;
    FILE *fd = fopen(filename, "r");
    char *total = malloc(sizeof(char));
    char *tmp;
    char *tmp2;
    total[0] = '\0';
    while (1) {
        size = getline(&line, &len, fd);
        if (size <= 0)
            break;
        tmp = total;
        tmp2 = my_strcat(" ", line);
        total = my_strcat(total, tmp2) - return_free(tmp) - return_free(tmp2);
    }
    free(line);
    fclose(fd);
    return total;
}
