/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** champions_numbers
*/

#include "header.h"

int get_biggest_number(corewar_t *glob)
{
    player_t *tmp = glob->players;
    int biggest = 0;

    for (; tmp; tmp = tmp->next)
        if (tmp->prog_number > biggest)
            biggest = tmp->prog_number;
    if (biggest < get_number_of_players(glob->players))
        return get_number_of_players(glob->players);
    return biggest;
}

static int set_players_specific_numbers(int i)
{
    if (i == 1)
        FATAL("Two players have the same number !");
    else
        return 1;
    return 0;
}

static void set_first_available_number(int *num, player_t *tmp, int biggest)
{
    int i = 0;

    for (; i < biggest; i++) {
        if (num[i] == 0) {
            tmp->prog_number = i + 1;
            tmp->registers[0] = tmp->prog_number;
            num[i] = 1;
            break;
        }
    }
}

void set_players_numbers(corewar_t *glob)
{
    int biggest = get_biggest_number(glob);
    int nb_players = get_number_of_players(glob->players);
    int *num = malloc(sizeof(int) * biggest);
    player_t *tmp = glob->players;
    int j = 0;

    for (int i = 0; i < biggest; num[i++] = 0);
    for (; tmp; tmp = tmp->next) {
        if (tmp->prog_number - 1 >= 0)
            j = num[tmp->prog_number - 1];
        if (tmp->prog_number > 0) {
            num[tmp->prog_number - 1] = set_players_specific_numbers(j);
            tmp->registers[0] = tmp->prog_number;
        }
    }
    for (tmp = glob->players; tmp; tmp = tmp->next)
        if (tmp->prog_number == 0)
            set_first_available_number(num, tmp, biggest);
    free(num);
}

int get_number_of_players(player_t *list)
{
    int nb = 0;

    while (list) {
        nb++;
        list = list->next;
    }
    return nb;
}
