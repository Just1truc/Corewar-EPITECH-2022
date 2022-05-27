/*
** EPITECH PROJECT, 2021
** project name
** File description:
** simple description
*/

#ifndef PROTO_H_
    #define PROTO_H_

void init_window(void);
void init_colors(void);
int main(int ac, char **av);
int error_handling(int ac, char **av);
int print_speed_screen(corewar_t *glob);
int is_nbr(char *str);
int my_getnbr(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
char **my_split(char *str, char *delim);
char *select_champ(int i, int *cursor);
int print_selection(char **title);
champ_t *get_list_of_champions(void);
void my_putstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);
int my_arraylen(int *array);
char *int_to_base(unsigned char nbr, int base);
int check_int_array(int *array, int *auth);
char *my_strncpy(char *src, char *dest, int n);
int is_in_list(char *str, char **tab);
int bin2int(char *str);
int uns_bin2int(char *str);
int bin2int_w_byte(char *str, int bytes);
int uns_bin2int_w_byte(char *str, int bytes);
char *my_strncat(char *str1, char *str2, int n1, int n2);
char *my_strdup(char *src);
char *my_strndup(char *src, int size);
char *my_wcopy(char *src, char *dest, int size, int depart);
void add_player(player_t **list, player_t *player);
void free_player(player_t *tmp);
void delete_first_player(player_t **list);
int delete_player(player_t **list, int load_address);
void free_players(player_t *list);
void load_in_memory(unsigned char *src,
unsigned char *dest, int size, int off);
void load_player(unsigned char *src, unsigned char *dest, int size, int off);
void load_color(unsigned char *dest, int size, int off, int color);
void set_load_addresses(player_t **list);
void load_champions(corewar_t *glob);
int get_player_size(int fd);
int get_magic(int fd);
char *get_name(int fd);
char *get_comment(int fd);
int print_win_screen(corewar_t *glob);
int get_alive_players(player_t *list);
int get_biggest_number(corewar_t *glob);
void set_players_numbers(corewar_t *glob);
int get_number_of_players(player_t *list);
player_t *create_player(char *path, int load_address, int prog_number);
int set_register(player_t *player);
void get_champion(player_t *player);
void print_memory(unsigned char *memory);
void print_hexadecimal(unsigned char nbr);
void print_usage(void);
int print_menu(void);
void print_win(int prog_number, char *name);
void print_equality(void);
void print_alive(int prog_number, char *name);
int check_add(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int add_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_ld(int *args, player_t *player, corewar_t *corewar, int *prototype);
int ld_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_st(int *args, player_t *player, corewar_t *corewar, int *prototype);
int fill_int_w_val(char c);
int st_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_sub(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int sub_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_and(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int and_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_or(int *args, player_t *player, corewar_t *corewar, int *prototype);
int or_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_xor(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int xor_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_zjmp(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int zjmp_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int get_val(int val, int type, corewar_t *corewar, player_t *player);
int check_ldi(int *args, player_t *player, corewar_t *corewar, int *prototype);
int ldi_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int get_val_l(int val, int type, corewar_t *corewar, player_t *player);
int check_lldi(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int lldi_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_lld(int *args, player_t *player, corewar_t *corewar, int *prototype);
int lld_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_sti(int *args, player_t *player, corewar_t *corewar, int *prototype);
int load_register(int registre, unsigned char *memory, int start);
void print_bytes(int depart, corewar_t *corewar, int bytes_nbr);
int sti_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int aff_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_aff(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int fork_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int lfork_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_fork(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_lfork(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_regiters_type(int *args, int *prototype);
int check_command_validity(int command, int *prototype, int id);
int check_command(player_t *player, corewar_t *corewar);
int get_tab_id_by_code(int code);
int get_byte_size(int command, int type);
int *get_args(int *prototype, player_t *player, corewar_t *corewar, int *pc);
int execute_command(player_t *player, corewar_t *corewar);
int get_mod(int number, int modulo);
int *get_prototype(int proto);
int check_live(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int get_linked_list_length(player_t *players);
int get_player_nbr(player_t *player_list);
int live_function(int *args, player_t *player,
corewar_t *corewar, int *prototype);
int check_execution(corewar_t *corewar, player_t *tmp);
int scheduling(corewar_t *corewar);
int free_int(int *array);
void my_getopt(int ac, char **av, corewar_t *glob);
int check_win(player_t *player);
void exec_nbr_live(corewar_t *glob);
void print_maps(unsigned char *map);
int vm(int ac, char **av);

#endif /* PROTO_H_ */
