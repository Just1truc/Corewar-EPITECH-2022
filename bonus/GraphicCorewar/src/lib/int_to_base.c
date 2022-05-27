/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** int_to_base
*/

#include "header.h"

static char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp;

    while (i <= j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

char *int_to_base(unsigned char nbr, int base)
{
    int i = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * (size + 1));
    char base_str[] = "0123456789abcdef";

    for (; nbr != 0; nbr /= base) {
        str[i++] = base_str[nbr % base];
        size++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}
