/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** loader
*/

#include "header.h"

void load_in_memory(unsigned char *src,
unsigned char *dest, int size, int off)
{
    for (int i = 0; i < size; i++)
        dest[(off + i) % MEM_SIZE] = src[i];
}

void load_player(unsigned char *src, unsigned char *dest, int size, int off)
{
    for (int i = 0; i < size; i++) {
        if (dest[(i + off) % MEM_SIZE] != 0)
            FATAL("Overlap detected !");
        else
            dest[(i + off) % MEM_SIZE] = src[i];
    }
}

void load_color(unsigned char *dest, int size, int off, int color)
{
    for (int i = 0; i < size; i++) {
        dest[(i + off) % MEM_SIZE] = color;
    }
}

void set_load_addresses(player_t **list)
{
    player_t *tmp = *list;
    int nb_players = get_number_of_players(*list);
    int i = 0;

    while (tmp) {
        if (tmp->load_address < 0)
            tmp->load_address = MEM_SIZE / nb_players * i;
        tmp = tmp->next;
        i++;
    }
}

void load_champions(corewar_t *glob)
{
    player_t *tmp = glob->players;
    glob->player_number = 0;

    set_load_addresses(&glob->players);
    while (tmp) {
        glob->player_number++;
        get_champion(tmp);
        load_player(tmp->content, glob->memory, tmp->size, tmp->load_address);
        load_color(glob->color, tmp->size, tmp->load_address, tmp->prog_number % 8);
        tmp = tmp->next;
    }
}
