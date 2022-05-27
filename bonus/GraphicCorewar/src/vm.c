/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** vm
*/

#include "header.h"

void print_hexa_maps(corewar_t *glob);

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
    player_t *tmp = glob->players;

    if ((glob->cycle_to_die - CYCLE_DELTA < 1000 && glob->cycle_to_die >= 1000) || (glob->cycle_to_die - CYCLE_DELTA < 100 && glob->cycle_to_die >= 100) || (glob->cycle_to_die - CYCLE_DELTA < 10 && glob->cycle_to_die >= 10)) {
        clear();
        print_hexa_maps(glob);
        for (int i = 0; tmp; tmp = tmp->next) {
            attron(COLOR_PAIR((tmp->prog_number == 0 ? 8 : tmp->prog_number % 8)));
            if (tmp->fork == 0)
                mvprintw(i++ * 2 + 5, 288, tmp->name);
            attroff(COLOR_PAIR((tmp->prog_number == 0 ? 8 : tmp->prog_number % 8)));
        }   
        refresh();
    } 
    if (glob->cycle_to_die - CYCLE_DELTA < 0 || glob->cycle_to_die == 1)
        glob->cycle_to_die = 1;
    else
        glob->cycle_to_die -= CYCLE_DELTA;
    glob->nbr_live = 0;
}

static void exec_cycle(corewar_t *glob, int i)
{
    scheduling(glob);
    mvprintw(0, 288, "Cycle : %d", i);
    mvprintw(1, 288, "Death Cycle : %d", glob->cycle_to_die);
    mvprintw(2, 288, "Player_number : %d", glob->player_number);
    refresh();
    if (i % glob->cycle_to_die == 0)
        cycle_to_kill(glob);
    if (glob->dump > 0 && glob->dump == i)
        print_memory(glob->memory);
    usleep(3000 / glob->speed);
}

void print_maps(unsigned char *map)
{
    char c;
    int cur = 0;
    for (int i = 0, j = 0; i < MEM_SIZE; i++) {
        attron(COLOR_PAIR((map[i] == 0) ? 8 : (int)map[i]));
        mvprintw(i / 96, i % 96 + j, "0%c", map[i] + '0');
        j += 2;
        if (i % 96 >= 9)
            j = 0;
        attroff(COLOR_PAIR((map[i] == 0) ? 8 : (int)map[i]));
    }
}

void print_hexa_maps(corewar_t *glob)
{
    for (int i = 0, j = 0; i < MEM_SIZE; i++) {
        attron(COLOR_PAIR((glob->color[get_mod(i, MEM_SIZE)] == 0) ? 8 : (int)glob->color[get_mod(i, MEM_SIZE)] % 8));
        mvprintw(get_mod(i, MEM_SIZE) / 96, (get_mod(i, MEM_SIZE) % 96) * 3, "%.2x", glob->memory[get_mod(i, MEM_SIZE)]);
        attroff(COLOR_PAIR((glob->color[get_mod(i, MEM_SIZE)] == 0) ? 8 : (int)glob->color[get_mod(i, MEM_SIZE)] % 8));
    }
}

int vm(int ac, char **av)
{
    corewar_t glob = {.cycle_to_die = CYCLE_TO_DIE};
    glob.memory = malloc(sizeof(char) * MEM_SIZE);
    glob.color = malloc(sizeof(char) * MEM_SIZE);
    player_t *tmp;

    for (int i = 0; i < MEM_SIZE; glob.memory[i++] = 0);
    for (int i = 0; i < MEM_SIZE; glob.color[i++] = 0);
    my_getopt(ac, av, &glob);
    if (get_number_of_players(glob.players) < 2)
        FATAL("TOO FEW CHAMPIONS !");
    print_speed_screen(&glob);
    set_players_numbers(&glob);
    set_register(glob.players);
    load_champions(&glob);
    clear();
    // print_maps(glob.color);
    print_hexa_maps(&glob);
    refresh();
    glob.winner = glob.players->prog_number;
    glob.winner_name = my_strdup(glob.players->name);
    glob.winner_comment = my_strdup(glob.players->comment);
    scheduling(&glob);
    tmp = glob.players;
    for (int i = 0; tmp; tmp = tmp->next, i++) {
        attron(COLOR_PAIR((tmp->prog_number == 0 ? 8 : tmp->prog_number % 8)));
        mvprintw(i * 2 + 5, 288, tmp->name);
        attroff(COLOR_PAIR((tmp->prog_number == 0 ? 8 : tmp->prog_number % 8)));
    }
    for (int i = 0; glob.players && !check_win(glob.players); i++)
        exec_cycle(&glob, i);
    print_win_screen(&glob);
    endwin();
    if (!glob.players) {
        print_win(glob.winner, glob.winner_name);
    } else
        print_win(glob.players->prog_number, glob.players->name);
    free_players(glob.players);
    free(glob.memory);
    return EXIT_SUCCESS;
}
