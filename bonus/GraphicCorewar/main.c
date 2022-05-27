/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** main
*/

#include "header.h"

void init_window(void)
{
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    clear();
    refresh();
}

void init_colors(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, 0);
    init_pair(1, COLOR_RED, 0);
    init_pair(2, COLOR_GREEN, 0);
    init_pair(3, COLOR_YELLOW, 0);
    init_pair(4, COLOR_BLUE, 0);
    init_pair(5, COLOR_MAGENTA, 0);
    init_pair(6, COLOR_CYAN, 0);
    init_pair(7, COLOR_WHITE, 0);
    init_pair(0, COLOR_BLACK, 0);
    init_pair(11, COLOR_WHITE, COLOR_RED);
    init_pair(12, COLOR_WHITE, COLOR_GREEN);
    init_pair(13, COLOR_WHITE, COLOR_YELLOW);
    init_pair(14, COLOR_WHITE, COLOR_BLUE);
    init_pair(15, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(16, COLOR_WHITE, COLOR_CYAN);
    init_pair(17, COLOR_WHITE, COLOR_WHITE);
    init_pair(8, 8, 0);
    init_pair(9, COLOR_WHITE, 0 );
}

int main(int ac, char **av)
{
    setlocale(LC_ALL, "");
    initscr();
    init_colors();
    init_window();
    return (print_menu());
}
