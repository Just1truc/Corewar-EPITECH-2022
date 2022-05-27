/*
** EPITECH PROJECT, 2022
** asm
** File description:
** encrypt_args
*/

#include "op.h"

static const char *indexs[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lfork",
    "lldi",
    NULL
};

void display_direct(char *arg, int *both, char *command, line_t **lines)
{
    int val;
    if (check_nbr(&arg[1]))
        val = getnbr(&arg[1]);
    else
        val = get_label_call_value(&arg[2], lines, both[1]);
    display_value(val, both[0],
    (is_in_list(command, (char **)indexs)) ? IND_SIZE : DIR_SIZE);
}

void display_indirect(char *arg, int *both, line_t **lines)
{
    int val;
    if (check_nbr(arg))
        val = getnbr(arg);
    else
        val = get_label_call_value(&arg[1], lines, both[1]);
    display_value(val, both[0], IND_SIZE);
}

void display_encrypt(char **args, line_t **lines, char *command, int *both)
{
    int i;
    int id;
    long long int val;

    for (id = 0; !my_strcmp(op_tab[id].mnemonique, command); id++);
    for (i = 0; args[i]; i++) {
        val = getnbr(&(args[i])[1]);
        if (is_direct(args[i]))
            display_direct(args[i], both, command, lines);
        if (is_indirect(args[i]))
            display_indirect(args[i], both, lines);
        if (is_register(args[i]))
            display_value(val, both[0], 1);
    }
}
