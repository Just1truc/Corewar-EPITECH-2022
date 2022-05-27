/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_mod
*/

#include "header.h"

int get_mod(int number, int modulo)
{
    return (number < 0) ? number % MEM_SIZE + MEM_SIZE : number % MEM_SIZE;
}
