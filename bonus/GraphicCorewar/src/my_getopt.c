/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** my_getopt
*/

#include "header.h"

static int is_good_prog_number(int prog_number)
{
    if (prog_number < 1)
        FATAL("-n option value must be between 1 and 4");
    return TRUE;
}

static int get_option(corewar_t *glob, char **av, int ac, int i)
{
    player_t *player = create_player(NULL, -1, 0);
    for (int j = 0; i < ac && (av[i][0] == '-' || is_nbr(av[i])); i++, j++) {
        if (j == 3)
            FATAL("TOO MANY OPTIONS !");
        if (my_strcmp(av[i], "-a") == 0 && av[i + 1] && is_nbr(av[i + 1])) {
            player->load_address = my_getnbr(av[i++ + 1]);
            continue;
        }
        if (my_strcmp(av[i], "-n") == 0 && av[i + 1] && is_nbr(av[i + 1])) {
            player->prog_number = my_getnbr(av[i++ + 1]);
            is_good_prog_number(player->prog_number);
            continue;
        } else
            FATAL("Bad options or bad options value !");
    }
    (av[i]) ? player->path = av[i] : 0;
    if (player->path == NULL)
        FATAL("Pas de name bouffon !");
    add_player(&glob->players, player);
    return i;
}

static void check_usage_option(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0) {
            print_usage();
            exit(EXIT_SUCCESS);
        }
    }
}

static void get_command(int ac, char **av, corewar_t *glob, int *obj)
{
    int i = obj[0];
    int dump = obj[1];

    if (my_strcmp(av[i], "-dump") == 0 && av[i + 1] != NULL &&
    is_nbr(av[i + 1])) {
        dump++;
        glob->dump = my_getnbr(av[i++ + 1]);
    } else if (av[i][0] == '-')
        i = get_option(glob, av, ac, i);
    else
        add_player(&glob->players, create_player(av[i], -1, 0));
    obj[0] = i;
    obj[1] = dump;
}

void my_getopt(int ac, char **av, corewar_t *glob)
{
    int dump = 0;
    int *obj = malloc(sizeof(int) * 2);

    obj[0] = 1;
    obj[1] = 0;
    check_usage_option(ac, av);
    for (int i = 1; i < ac; i++) {
        obj[0] = i;
        obj[1] = dump;
        get_command(ac, av, glob, obj);
        i = obj[0];
        dump = obj[1];
    }
    if (dump > 1)
        FATAL("Double definition of option dump.");
}
