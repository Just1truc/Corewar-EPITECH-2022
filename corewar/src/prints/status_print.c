/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** status_print
*/

#include "header.h"

void print_win(int prog_number, char *name)
{
    write(1, "The player ", 11);
    my_put_nbr(prog_number);
    write(1, "(", 1);
    my_putstr(name);
    write(1, ") has won.\n", 11);
}

void print_equality(void)
{
    write(1, "It's an equality\n", 17);
}

void print_alive(int prog_number, char *name)
{
    write(1, "The player ", 11);
    my_put_nbr(prog_number);
    write(1, "(", 1);
    my_putstr(name);
    write(1, ") is alive.\n", 12);
}
