/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** ld
*/

#include "header.h"

int check_ld(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int ld_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    char bin[5] = {0};

    player->registers[args[1] - 1] = args[0];
    if (proto_to_type[prototype[0]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, REG_SIZE,
        get_mod(player->pc + args[0] % IDX_MOD, MEM_SIZE));
        player->registers[args[1] - 1] = uns_bin2int_w_byte(bin, REG_SIZE);
    }
    return 0;
}
