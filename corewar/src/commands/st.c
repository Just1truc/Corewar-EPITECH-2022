/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** st
*/

#include "header.h"

int check_st(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int fill_int_w_val(char c)
{
    int val = 0;
    for (int i = 0; i < 4; i++) {
        val <<= 8;
        val += c;
    }
    return val;
}

int st_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    if (proto_to_type[prototype[1]] == T_REG)
        player->registers[args[1] - 1] = player->registers[args[0] - 1];
    else {
        load_register(player->registers[args[0] - 1], corewar->memory,
        get_mod(player->pc + args[1]
        % IDX_MOD, MEM_SIZE));
    }
    return 0;
}
