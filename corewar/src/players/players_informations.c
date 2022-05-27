/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** players_informations
*/

#include "header.h"

int get_player_size(int fd)
{
    int offset = 136;
    char bin[5] = {0};

    bin[4] = '\0';
    lseek(fd, offset, SEEK_SET);
    read(fd, bin, 4);
    return uns_bin2int_w_byte((char *)bin, 4);
}

int get_magic(int fd)
{
    int magic = 0;
    char bin[5] = {0};

    bin[4] = '\0';
    lseek(fd, 0, SEEK_SET);
    read(fd, bin, 4);
    magic = bin2int((char *)bin);
    if (magic != -1473805)
        FATAL("Bad magic number !");
    return TRUE;
}

char *get_name(int fd)
{
    int offset = 4;
    char *name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));

    for (int i = 0; i < (PROG_NAME_LENGTH + 1); name[i++] = 0);
    lseek(fd, offset, SEEK_SET);
    read(fd, name, PROG_NAME_LENGTH);
    return name;
}

char *get_comment(int fd)
{
    int offset = 136;
    char *comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));

    for (int i = 0; i < (COMMENT_LENGTH + 1); comment[i++] = 0);
    lseek(fd, offset, SEEK_SET);
    read(fd, comment, COMMENT_LENGTH);
    return comment;
}

int get_alive_players(player_t *list)
{
    int i = 0;
    int num[4] = {0};

    for (player_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->alive == TRUE && num[tmp->prog_number - 1] == 0) {
            num[tmp->prog_number - 1] = 1;
            i++;
        }
    }
    return i;
}
