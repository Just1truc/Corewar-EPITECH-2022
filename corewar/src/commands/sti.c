/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** sti
*/

#include "header.h"

int check_sti(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int load_register(int registre, unsigned char *memory, int start)
{
    int tmp;

    for (int i = 0; i < 4; i++) {
        tmp = registre >> (8 * (3 - i));
        memory[get_mod(start + i, MEM_SIZE)] = (char)tmp;
        registre -= tmp << (8 * (3 - i));
    }
}

int sti_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    int val1 = args[1];
    int val2 = args[2];
    char bin[5] = {0};
    if (proto_to_type[prototype[1]] == T_REG)
        val1 = player->registers[args[1] - 1];
    if (proto_to_type[prototype[1]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, IND_SIZE,
        get_mod(player->pc + args[1] % IDX_MOD, MEM_SIZE));
        val1 = uns_bin2int_w_byte(bin, IND_SIZE);
    }
    if (proto_to_type[prototype[2]] == T_REG)
        val2 = player->registers[args[2] - 1];
    if (proto_to_type[prototype[2]] == T_IND) {
        my_wcopy((char *)corewar->memory, bin, IND_SIZE,
        get_mod(player->pc + args[2] % IDX_MOD, MEM_SIZE));
        val2 = uns_bin2int_w_byte(bin, IND_SIZE);
    }
    load_register(player->registers[args[0] - 1], corewar->memory, get_mod(
    player->pc + (val1 + val2) % IDX_MOD, MEM_SIZE));
    return 0;
}
