/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** linked_list
*/

#include "header.h"

void add_player(player_t **list, player_t *player)
{
    player_t *tmp = *list;

    player->next = NULL;
    if (tmp == NULL) {
        *list = player;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = player;
}

void free_player(player_t *tmp)
{
    if (tmp->comment != NULL)
        free(tmp->comment);
    if (tmp->content != NULL)
        free(tmp->content);
    if (tmp->name != NULL)
        free(tmp->name);
    if (tmp->registers != NULL)
        free(tmp->registers);
}

void delete_first_player(player_t **list)
{
    player_t *tmp = NULL;

    if (!list[0])
        return;
    tmp = list[0];
    list[0] = list[0]->next;
    free_player(tmp);
}

int delete_player(player_t **list, int load_address)
{
    player_t *tmp = NULL;
    player_t *prev = *list;

    if (prev->load_address == load_address) {
        delete_first_player(list);
        return EXIT_SUCCESS;
    }
    if (!prev || !prev->next)
        return (EXIT_ERROR);
    tmp = prev->next;
    while (tmp && tmp->load_address != load_address) {
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp) {
        prev->next = tmp->next;
        free_player(tmp);
    }
    return EXIT_SUCCESS;
}

void free_players(player_t *list)
{
    player_t *tmp = list;

    while (tmp) {
        list = list->next;
        free_player(tmp);
        tmp = list;
    }
}
