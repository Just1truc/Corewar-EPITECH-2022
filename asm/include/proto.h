/*
** EPITECH PROJECT, 2021
** project name
** File description:
** simple description
*/

#ifndef PROTO_H_
    #define PROTO_H_

int main(int ac, char **ag);
int parser(char *filename);
int my_atoi(char *str);
int check_string(char *str, char *auth);
int check_sub(char *string, char *sub);
int my_boostlen(char *str);
int my_tablen(char **str);
char *my_strcat(char *s1, char *s2);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
void ft_putchar(char c);
void my_putnbr(int nb);
int get_strlen(char *str);
int get_len_of_word(char *str, int i, char *dels);
int is_one_of(char c, char *str);
char **my_split(char *str, char *dels);
void my_putstr(char *s);
int endswidth(char *str, char *end);
void my_puterr(char *str);
char *delete_char(char *str, char c);
char *replace(char *str, char c1, char c2);
void my_strcpy(char *src, char *dest);
int getnbr(char *str);
int check_nbr(char *str);
int is_in_list(char *str, char **tab);
void printinfo(char *bin_name);
char *get_file(char *filename);
int free_tab(char **tab);
int return_free(char *str);
int free_line_struct(line_t **file);
int return_freeint(int *array);
int check_label(char *str);
int check_command(char *str);
int check_comment(char *str);
int check_name(char *str);
int check_exist(char *str, int line);
int *get_params(char **args, char **labels);
int my_arraylen(int *array);
int check_params(char **args, char *command_name, int line_nbr, char **labels);
int check_register(char *str);
int check_direct(char *str, char **labels);
int check_indirect(char *str, char **labels);
char *my_strdup_wt_comments(char *str);
line_t **clean_tab(char **lines);
int return_puterr(char *str, int return_value, int line);
int check_error_on_order(char **splitted, header_t *header, int line);
int check_header_info(char **splitted,
header_t *head, int line_nbr, char *line);
int check_line(char *line, header_t *head, int line_nbr, char **labels);
void check_error(line_t **file);
int count_labels(line_t **lines);
char **get_labels(line_t **file);
int my_listlen(line_t **file);
void cleanup_close(int *fd);
int get_name(char *line, header_t *header, int line_nbr, int boole);
int get_comment(char *line, header_t *header, int line_nbr, int boole);
int get_little_big(int i);
void my_print_tab(char **tab);
int get_bytes_nbr(int *array, char *command_name);
int calcul_cost(char *line, char **labels);
void display_header(header_t *header, int fd);
int show_header(line_t **lines, int fd, char **labels);
line_t **get_label_list(line_t **file);
char get_prototype(int *array);
char **get_list(line_t **label_list);
int is_register(char *str);
int is_direct(char *str);
int is_indirect(char *str);
void display_value(long long int val, int fd, int byte_size);
int get_id_of_label(char *label, line_t **lines);
int calcul_label_distance(int call, int label, line_t **lines);
int get_label_call_value(char *label, line_t **lines, int depart);
void display_direct(char *arg, int *both, char *command, line_t **lines);
void display_indirect(char *arg, int *both, line_t **lines);
void display_encrypt(char **args, line_t **lines, char *command, int *both);
void display_label_command(line_t **file, char **labels,
int *both, char **splitted);
void encrypt_line(line_t **file, char **labels, int line_nbr, int fd);
void encrypt(line_t **lines, char *file);

#endif /* PROTO_H_ */
