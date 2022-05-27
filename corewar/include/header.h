/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include "op.h"

    #define EXIT_SUCCESS    0
    #define EXIT_FAILRURE   1
    #define EXIT_ERROR      84
    #define TRUE            1
    #define FALSE           0

typedef struct player_s {
    char *path;
    int prog_number;
    int load_address;
    char *comment;
    char *name;
    unsigned char *content;
    unsigned int size;
    int status;
    int executing;
    int alive;
    int pc;
    int carry;
    struct player_s *next;
    int *registers;
} player_t;

typedef struct corewar {
    int nbr_live;
    int cycle_to_die;
    int dump;
    unsigned char *memory;
    unsigned char *color;
    player_t *players;
    int player_number;
    int winner;
    char *winner_name;
} corewar_t;

    #define FATAL(msg) \
        do { \
        my_putstr(msg); \
        my_putstr("\n"); \
        exit(EXIT_ERROR); \
        } while (0) \

/* src/lib */
char *int_to_base(unsigned char nbr, int base);
int my_strlen(char *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char *str);
int my_strcmp(char const *s1, char const *s2);
int is_nbr(char *str);

/* src/errors/error_handling.c */
int error_handling(int ac, char **av);

/* src/my_getopt.c */
void my_getopt(int ac, char **av, corewar_t *glob);

char *my_strndup(char *src, int size);
char *my_strdup(char *src);

/* src/vm.c */
void load_in_memory(unsigned char *src, unsigned char *dest,
int size, int off);
int vm(int ac, char **av);

/* src/prints/print_memory.c */
void print_hexadecimal(unsigned char nbr);
void print_memory(unsigned char *memory);
int delete_player(player_t **list, int load_address);

/* src/prints/print_usage.c */
void print_usage(void);

/* src/players/linked_list.c */
void add_player(player_t **list, player_t *player);
void free_players(player_t *players);

/* src/players/loader.c */
void load_in_memory(unsigned char *src, unsigned char *dest,
int size, int off);
void set_load_addresses(player_t **list);
void load_champions(corewar_t *glob);

/* src/players/players_informations.c */
int get_player_size(int fd);
int get_magic(int fd);
char *get_name(int fd);
char *get_comment(int fd);
int get_alive_players(player_t *list);

/* src/players/player.c */
player_t *create_player(char *name, int load_address, int prog_number);
void get_champion_actions(char *pathname);

/* src/prints/status_print.c */
void print_win(int prog_number, char *name);
void print_equality(void);
void print_alive(int prog_number, char *name);

/* src/players/champions_numbers.c */
int get_number_of_players(player_t *players);
void set_players_numbers(corewar_t *glob);

    #include "proto.h"

#endif /* !HEADER_H_ */
