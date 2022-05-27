/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** add
*/

#include "header.h"

int check_add(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return 0;
}

int add_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    player->registers[args[2] - 1] = player->registers[args[0] - 1]
    + player->registers[args[1] - 1];
    return 0;
}
