/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-tetris-leo.dubosclard
** File description:
** my_getnbr
*/

#include "header.h"

int my_getnbr(char *str)
{
    int number = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == 45 || str[i] == 43) {
        if (str[i] == 45)
            sign *= -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        number = number * 10 + (str[i] - 48);
        i++;
    }
    return (number * sign);
}
