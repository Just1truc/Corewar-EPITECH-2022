/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display integer
*/

#include "header.h"

int my_put_nbr(int nb)
{
    unsigned int nbr;

    if (nb < 0) {
        my_putchar('-');
        nbr = -nb;
    } else {
        nbr = nb;
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + 48);
    return 0;
}
