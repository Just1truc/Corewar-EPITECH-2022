/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** my_putstr
*/

#include "header.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
