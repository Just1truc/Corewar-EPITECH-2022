/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** player
*/

#include "header.h"

player_t *create_player(char *path, int load_address, int prog_number)
{
    player_t *player = malloc(sizeof(player_t));

    player->path = path;
    player->load_address = load_address;
    player->prog_number = prog_number;
    player->comment = NULL;
    player->content = NULL;
    player->name = NULL;
    player->alive = TRUE;
    player->carry = 1;
    player->next = NULL;
    player->registers = malloc(sizeof(int) * (REG_NUMBER));
    for (int i = 0; i < REG_NUMBER; player->registers[i++] = 0);
    player->executing = FALSE;
    player->status = 0;
    return player;
}

int set_register(player_t *player)
{
    for (; player; player = player->next) {
        player->registers[0] = player->prog_number;
    }
}

void get_champion(player_t *player)
{
    int fd = open(player->path, O_RDONLY);
    int offset = sizeof(header_t);
    size_t size = 0;

    if (fd < 0)
        FATAL("Can't open file");
    get_magic(fd);
    player->name = get_name(fd);
    player->comment = get_comment(fd);
    player->size = get_player_size(fd);
    player->pc = player->load_address;
    lseek(fd, offset, SEEK_SET);
    player->content = malloc(sizeof(unsigned char *) * player->size);
    if ((size = read(fd, player->content, player->size)) < 0)
        FATAL("Can't read file\n");
}
