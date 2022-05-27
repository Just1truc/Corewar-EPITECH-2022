/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** main
*/

#include "op.h"

int main(int ac, char **ag)
{
    if (ac > 2)
        return 84;
    if (ac == 2 && my_strcmp(ag[1], "-h") == 0)
        printinfo(ag[0]);
    else if (ac == 2 && endswidth(ag[1], ".s") == TRUE)
        return parser(ag[1]);
    else {
        printinfo(ag[0]);
        return 84;
    }
    return 0;
}
