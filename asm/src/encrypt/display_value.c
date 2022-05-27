/*
** EPITECH PROJECT, 2022
** asm
** File description:
** display_value
*/

#include "op.h"

void display_value(long long int val, int fd, int byte_size)
{
    int res[] = {0};

    *res = get_little_big(val);
    *res = *res >> ((4 - byte_size) * 8);
    write(fd, &res, byte_size);
}
