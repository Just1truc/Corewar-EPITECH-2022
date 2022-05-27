/*
** EPITECH PROJECT, 2022
** asm
** File description:
** clean_up_close
*/

#include "op.h"

void cleanup_close(int *fd)
{
    if (*fd)
        close(*fd);
}
