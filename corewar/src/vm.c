/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** vm
*/

#include "header.h"

int check_win(player_t *player)
{
    int i = player->prog_number;

    for (; player; player = player->next) {
        if (player->prog_number != i)
            return FALSE;
    }
    return TRUE;
}

static void cycle_to_kill(corewar_t *glob)
{
    for (player_t *tmp = glob->players; tmp; tmp = tmp->next) {
        if (tmp->alive == FALSE)
            delete_player(&glob->players, tmp->load_address);
        else
            tmp->alive = FALSE;
    }
}

void exec_nbr_live(corewar_t *glob)
{
    if (glob->cycle_to_die - CYCLE_DELTA < 0 || glob->cycle_to_die == 1)
        glob->cycle_to_die = 1;
    else
        glob->cycle_to_die -= CYCLE_DELTA;
    glob->nbr_live = 0;
}

static void exec_cycle(corewar_t *glob, int i)
{
    scheduling(glob);
    if (i % glob->cycle_to_die == 0)
        cycle_to_kill(glob);
    if (glob->dump > 0 && glob->dump == i)
        print_memory(glob->memory);
}

int start_vm(int ac, char **av)
{
    corewar_t glob = {.cycle_to_die = CYCLE_TO_DIE};
    glob.memory = malloc(sizeof(char) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; glob.memory[i++] = 0);
    my_getopt(ac, av, &glob);
    if (get_number_of_players(glob.players) < 2)
        FATAL("TOO FEW CHAMPIONS !");
    set_players_numbers(&glob);
    set_register(glob.players);
    load_champions(&glob);
    scheduling(&glob);
    for (int i = 0; glob.players && !check_win(glob.players); i++)
        exec_cycle(&glob, i);
    if (!glob.players) {
        print_win(glob.winner, glob.winner_name);
    } else
        print_win(glob.players->prog_number, glob.players->name);
    free_players(glob.players);
    free(glob.memory);
    return EXIT_SUCCESS;
}
