/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** and
*/

#include "header.h"

int check_and(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return 0;
}

int and_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    int val1 = args[0];
    int val2 = args[1];
    char bin[5] = {0};

    if (proto_to_type[prototype[0]] == T_REG)
        val1 = player->registers[args[0] - 1];
    if (proto_to_type[prototype[0]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, IND_SIZE,
        get_mod(player->pc + args[0] % IDX_MOD, MEM_SIZE));
        val1 = uns_bin2int_w_byte(bin, IND_SIZE);
    }
    if (proto_to_type[prototype[1]] == T_REG)
        val2 = player->registers[args[1] - 1];
    if (proto_to_type[prototype[1]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, IND_SIZE,
        get_mod(player->pc + args[1] % IDX_MOD, MEM_SIZE));
        val2 = uns_bin2int_w_byte(bin, IND_SIZE);
    }
    player->registers[args[2] - 1] = val1 & val2;
    return 0;
}
