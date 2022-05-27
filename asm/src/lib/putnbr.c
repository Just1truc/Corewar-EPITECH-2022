/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** putnbr
*/

#include "op.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int nb)
{
    unsigned int nbr;

    if (nb < 0) {
        ft_putchar('-');
        nbr = -nb;
    } else
        nbr = nb;
    if (nbr >= 10)
        my_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}
