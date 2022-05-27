/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** zjmp
*/

#include "header.h"

int check_zjmp(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return 0;
}

int zjmp_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    if (player->carry == 0)
        return 0;
    player->pc = get_mod((player->pc + args[0] % IDX_MOD), MEM_SIZE);
    return 0;
}
