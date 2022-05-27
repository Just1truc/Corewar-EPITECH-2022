/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** binary_to_int
*/

#include "header.h"

int bin2int(char *str)
{
    int o = 0;

    for (int i = 0; i < 4; i++) {
        o <<= 8;
        o += str[i];
    }
    return o;
}

int uns_bin2int(char *str)
{
    int o = 0;

    for (int i = 0; i < 4; i++) {
        o <<= 8;
        o += (unsigned char)str[i];
    }
    return o;
}

int bin2int_w_byte(char *str, int bytes)
{
    int o = 0;

    for (int i = 0; i < bytes; i++) {
        o <<= 8;
        o += str[i];
    }
    return o;
}

int uns_bin2int_w_byte(char *str, int bytes)
{
    int o = 0;

    for (int i = 0; i < bytes; i++) {
        o <<= 8;
        o += (unsigned char)str[i];
    }
    return (bytes == 2) ? (short)o : o;
}
