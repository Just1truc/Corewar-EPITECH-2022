/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check_command
*/

#include "header.h"

static const int (*check_commands[])(int *, player_t *,
corewar_t *, int *) = {
    check_live,
    check_ld,
    check_st,
    check_add,
    check_sub,
    check_and,
    check_or,
    check_xor,
    check_zjmp,
    check_ldi,
    check_sti,
    check_fork,
    check_lld,
    check_lldi,
    check_lfork,
    check_aff,
    NULL
};

int check_regiters_type(int *args, int *prototype)
{
    int type;

    for (int i = 0; prototype[i]; i++) {
        type = proto_to_type[prototype[i]];
        if (type == T_REG && !(args[i] >= 1 && args[i] <= REG_NUMBER))
            return 0;
    }
    return 1;
}

int check_command_validity(int command, int *prototype, int id)
{
    if (command > 16 || command < 1)
        return 84;
    if (op_tab[id].nbr_args != my_arraylen(prototype)) {
        return 84;
    }
    return 0;
}

int check_command(player_t *player, corewar_t *corewar)
{
    int i;
    int command = corewar->memory[get_mod(player->pc, MEM_SIZE)];
    if (command > 16 || command < 1)
        return FALSE;
    int check = (op_tab[command - 1].weight == FALSE);
    int new_pc = (check) ? 0 : 1;
    int *prototype = get_prototype((check) ? (unsigned char)(T_DIR << 6)
    : corewar->memory[(player->pc + 1) % MEM_SIZE]);
    int *args = get_args(prototype, player, corewar, &new_pc);

    if (!args)
        return FALSE - free_int(prototype);
    if (args && !check_regiters_type(args, prototype))
        return FALSE - free_int(args) - free_int(prototype);
    if (check_commands[(int)corewar->memory[get_mod(player->pc, MEM_SIZE)]
    - 1](args, player, corewar, prototype) == 84)
        return FALSE - free_int(args) - free_int(prototype);
    free_int(args);
    free_int(prototype);
    return TRUE;
}
