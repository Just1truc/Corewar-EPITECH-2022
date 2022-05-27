/*
** EPITECH PROJECT, 2021
** aff
** File description:
** corewar
*/

#include "header.h"

int aff_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    char c = player->registers[args[0] - 1] % 256;

    write(1, &c, 1);
    return 0;
}

int check_aff(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return (0);
}
