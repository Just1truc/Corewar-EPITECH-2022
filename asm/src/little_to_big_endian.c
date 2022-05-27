/*
** EPITECH PROJECT, 2022
** asm
** File description:
** little_to_big_endian
*/

#include "op.h"

int get_little_big(int i)
{
    return (i & 0xff) << 24 | (i & 0xff00) << 8
    | (i & 0xff0000) >> 8 | ((i >> 24) & 0xff);
}
