/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-justin.duc
** File description:
** atoi
*/

#include "op.h"

int my_atoi(char *str)
{
    long long int nbr = 1;
    for (int i = 0; str[i++ + 1]; nbr *= 10);
    return (str[0] - '0') * nbr + ((str[1]) ? my_atoi(&str[1]) : 0);
}
