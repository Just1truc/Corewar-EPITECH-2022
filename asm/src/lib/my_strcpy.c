/*
** EPITECH PROJECT, 2022
** asm
** File description:
** my_strcpy
*/

#include "op.h"

void my_strcpy(char *src, char *dest)
{
    for (int i = 0; src[i]; dest[i] = src[i], i++);
}
