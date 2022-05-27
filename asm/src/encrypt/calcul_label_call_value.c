/*
** EPITECH PROJECT, 2022
** asm
** File description:
** calcul_label_call_value
*/

#include "op.h"

int calcul_label_distance(int call, int label, line_t **lines)
{
    int id;
    int cost = 0;
    char **labels = get_labels(lines);

    if (call > label)
        for (id = call - 1; id >= label;
        cost -= calcul_cost(lines[id]->str, labels), id--);
    if (call < label)
        for (id = call; id < label;
        cost += calcul_cost(lines[id]->str, labels), id++);
    return cost - free_tab(labels);
}

int get_label_call_value(char *label, line_t **lines, int depart)
{
    int id = get_id_of_label(label, lines);

    return calcul_label_distance(depart, id, lines);
}
