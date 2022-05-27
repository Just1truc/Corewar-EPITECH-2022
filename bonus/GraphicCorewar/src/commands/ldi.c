/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** ldi
*/

#include "header.h"

int get_val(int val, int type, corewar_t *corewar, player_t *player)
{
    char bin[3] = {0};
    if (type == T_IND) {
        my_wcopy((char *)corewar->memory, bin, IND_SIZE,
        get_mod(player->pc + val % IDX_MOD, MEM_SIZE));
        return uns_bin2int_w_byte(bin, IND_SIZE);
    }
    if (type == T_REG)
        return player->registers[val - 1];
    return val;
}

int check_ldi(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int ldi_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    int val1 = get_val(args[0], proto_to_type[prototype[0]], corewar, player);
    int val2 = get_val(args[1], proto_to_type[prototype[1]], corewar, player);
    int s = val1 + val2;
    char bin[5] = {0};

    my_wcopy((char *)corewar->memory, bin, REG_SIZE,
    (player->pc + s % IDX_MOD) % MEM_SIZE);
    player->registers[args[2] - 1] = uns_bin2int_w_byte(bin, REG_SIZE);
    return 0;
}
