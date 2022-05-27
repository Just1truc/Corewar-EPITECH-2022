/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lld
*/

#include "header.h"

int check_lld(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int lld_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    char bin[5] = {0};

    player->registers[args[1] - 1] = args[0];
    if (proto_to_type[prototype[0]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, REG_SIZE,
        get_mod(player->pc + args[0], MEM_SIZE));
        player->registers[args[1] - 1] = uns_bin2int_w_byte(bin, REG_SIZE);
    }
    return 0;
}
