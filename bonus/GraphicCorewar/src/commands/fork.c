/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** fork
*/

#include "header.h"

static player_t *copy_player(player_t *player, int *args, int is_l)
{
    player_t *new = malloc(sizeof(player_t));
    int i = 0;
    new->path = my_strdup(player->path);
    new->prog_number = player->prog_number;
    new->load_address = get_mod(player->pc + args[0] % IDX_MOD, MEM_SIZE);
    if (is_l)
        new->load_address = get_mod(player->pc + args[0], MEM_SIZE);
    new->comment = my_strndup(player->comment, COMMENT_LENGTH);
    new->name = my_strndup(player->name, PROG_NAME_LENGTH);
    new->content = my_strndup(player->content, player->size);
    new->size = player->size;
    new->status = 0;
    new->alive = player->alive;
    new->pc = new->load_address;
    new->carry = player->carry;
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    new->executing = FALSE;
    for (; i < REG_NUMBER; new->registers[i] = player->registers[i], i++);
    new->next = NULL;
    new->fork = 1;
    return new;
}

int fork_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    player_t *forked = copy_player(player, args, FALSE);

    add_player(&corewar->players, forked);
    corewar->player_number++;
    return 0;
}

int lfork_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    player_t *forked = copy_player(player, args, TRUE);

    corewar->player_number++;
    add_player(&corewar->players, forked);
    return 0;
}

int check_fork(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return 0;
}

int check_lfork(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    return 0;
}
