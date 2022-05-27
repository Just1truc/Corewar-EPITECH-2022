/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** live
*/

#include "header.h"

int check_live(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    int val = args[0];
    int max = 0;
    player_t *tmp = corewar->players;

    for (; tmp; max = (tmp->prog_number > max)
    ? tmp->prog_number : max, tmp = tmp->next);
    if (val < 1 || val > max) {
        return 84;
    }
    return 0;
}

int get_linked_list_length(player_t *players)
{
    int i;
    for (i = 0; players; players = players->next, i++);
    return i;
}

int get_player_nbr(player_t *player_list)
{
    int i = 1;
    int nbr = 0;
    player_t *tmp;
    int *array;
    int u;
    int max = 0;

    for (tmp = player_list; tmp; max = (tmp->prog_number > max)
    ? tmp->prog_number : max, tmp = tmp->next, i++);
    array = malloc(sizeof(int) * (max + 1));
    for (u = 0; u < max; array[u++] = '0');
    array[u] = 0;
    for (; player_list; player_list = player_list->next) {
        array[player_list->prog_number - 1] = '1';
    }
    for (i = 0; array[i]; nbr += (array[i] == '1') ? 1 : 0, i++);
    return nbr - free_int(array);
}

int live_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    player_t *tmp = corewar->players;
    int i = 0;

    corewar->nbr_live++;
    corewar->winner = player->prog_number;
    free(corewar->winner_name);
    corewar->winner_name = my_strdup(player->name);
    if (corewar->nbr_live >= NBR_LIVE)
        exec_nbr_live(corewar);
    print_alive(player->prog_number, player->name);
    for (; tmp; tmp = tmp->next) {
        if (tmp->prog_number == args[0]) {
            tmp->alive = TRUE;
        }
    }
    return 0;
}
