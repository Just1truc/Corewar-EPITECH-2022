/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** print_usage
*/

#include "header.h"

void print_usage(void)
{
    my_putstr("USAGE\n"
            "./corewar [-dump nbr_cycle] [[-n prog_number] [-n load_address]"
            " prog_name] ...\nDESCRIPTION\n"
            "-dump nbr_cycle dumps the memory after the nbr_cycle execution"
            " (if the round isn't\nalready over) with the following format:"
            " 32 bytes/line\nin hexadecimal (A0BCDEFE1DD3...)\n-n prog_number"
            " sets the next program's number. By default, the"
            " first free number\nin the parameter order\n"
            "-a load_address sets the next program's loading address"
            ". When no address is\nspecified, optimize the addresses so that"
            " the processes are as far\naway for each other as possible."
            " The addresses are MEM_SIZE modulo.\n");
}
