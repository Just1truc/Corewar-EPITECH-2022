/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** error_handling
*/

#include "header.h"

int error_handling(int ac, char **av)
{
    my_putstr(av[0]);
    my_put_nbr(ac);
    return EXIT_SUCCESS;
}
