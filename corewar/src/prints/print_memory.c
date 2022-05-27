/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** print_memory
*/

#include "header.h"

void print_memory(unsigned char *memory)
{
    for (int i = 0, j = 0; i < MEM_SIZE; i++, j++) {
        print_hexadecimal(memory[i]);
        my_putstr(" ");
        if (j == 31) {
            write(1, "\n", 1);
            j = -1;
        }
    }
}

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

void print_hexadecimal(unsigned char nbr)
{
    char *str = malloc(sizeof(char) * 34);
    char base[] = "0123456789abcdef";
    int i = 0;
    char tmp;

    for (; nbr > 0; i++) {
        tmp = base[nbr % 16];
        str[i] = tmp;
        nbr /= 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (my_strlen(str) == 1) {
        my_putstr("0");
        my_putstr(str);
    } else if (my_strlen(str) == 0)
        my_putstr("00");
    else
        my_putstr(str);
    free(str);
}
