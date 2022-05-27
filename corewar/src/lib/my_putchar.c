/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** my_putchar
*/

#include "header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
