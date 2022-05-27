/*
** EPITECH PROJECT, 2022
** asm
** File description:
** printinfo
*/

#include "op.h"

void printinfo(char *bin_name)
{
    my_putstr("USAGE\n");
    my_putstr(bin_name);
    my_putstr(" file_name[.s]\nDESCRIPTION\n");
    my_putstr("file_name file in assembly language to be converted to");
    my_putstr(" be into file_name.cor, an\nexecutable in Virtual Machine.\n");
}
