/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** execute_commad
*/

#include "header.h"

static const char *indexs[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lfork",
    "lldi",
    NULL
};

static const int (*exec_commands[])(int *, player_t *, corewar_t *, int *) =
{
    live_function,
    ld_function,
    st_function,
    add_function,
    sub_function,
    and_function,
    or_function,
    xor_function,
    zjmp_function,
    ldi_function,
    sti_function,
    fork_function,
    lld_function,
    lldi_function,
    lfork_function,
    aff_function,
    NULL
};

int get_tab_id_by_code(int code)
{
    int id;
    for (id = 0; op_tab[id].mnemonique && op_tab[id].code != code; id++);
    return id;
}

int get_byte_size(int command, int type)
{
    int id = get_tab_id_by_code(command);

    return (is_in_list(op_tab[id].mnemonique, (char **)indexs)
    && type != T_REG) ? 2 : sizes[type];
}

int *get_args(int *prototype, player_t *player, corewar_t *corewar, int *pc)
{
    int *args = malloc(sizeof(int) * 5);
    char bin[5] = {0};
    int type;
    int i = 0;
    int u = 0;
    int command = corewar->memory[get_mod(player->pc, MEM_SIZE)];
    args[0] = 0;
    if (check_command_validity(command, prototype, command - 1) == 84)
        return NULL - free_int(args);
    for (int size = 0; prototype[i]; i++, u += size) {
        type = proto_to_type[prototype[i]];
        if ((op_tab[command - 1].type[i] & type) != type)
            return NULL - free_int(args);
        size = get_byte_size(command, type);
        args[i] = uns_bin2int_w_byte(my_wcopy((char *)corewar->memory, bin,
        size, player->pc + *pc + 1 + u), size);
    }
    args[i] = 0;
    pc[0] = (1 + pc[0] + u) % MEM_SIZE;
    return args;
}

int execute_command(player_t *player, corewar_t *corewar)
{
    int command = corewar->memory[get_mod(player->pc, MEM_SIZE)];
    int check = (op_tab[command - 1].weight == FALSE);
    int new_pc[] = {(check) ? 0 : 1};
    int *prototype = get_prototype((check) ? (unsigned char)(T_DIR << 6)
    : corewar->memory[(player->pc + 1) % MEM_SIZE]);
    int *args = get_args(prototype,
    player, corewar, new_pc);

    exec_commands[(int)command - 1](args, player, corewar, prototype);
    if (command != 9)
        player->pc += *new_pc;
    free_int(args);
    free_int(prototype);
}
