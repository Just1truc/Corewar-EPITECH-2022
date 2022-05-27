/*
** EPITECH PROJECT, 2022
** asm
** File description:
** free_line_struct
*/

#include "op.h"

int free_line_struct(line_t **file)
{
    for (int i = 0; file[i]; free(file[i]->str), free(file[i++]));
    free(file);
    return 0;
}
