/*
** EPITECH PROJECT, 2021
** gamescreen
** File description:
** corewar
*/

#include "header.h"

int my_boostlen(char *str)
{
    return ((*str) ? 1 + my_boostlen(&str[1]) : 0);
}

char *my_strcat(char *s1, char *s2)
{
    char *r = malloc(sizeof(char) * (my_boostlen(s1) + my_boostlen(s2) + 1));
    int i;
    int u;
    for (i = 0; s1[i]; r[i] = s1[i], i++);
    for (u = i; s2[i - u]; r[i] = s2[i - u], i++);
    r[i] = 0;
    return r;
}

int return_free(char *str)
{
    free(str);
    return (0);
}

char *get_file(char *filename)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t size = 0;
    FILE *fd = fopen(filename, "r");
    char *total = malloc(sizeof(char));
    char *tmp;
    char *tmp2;
    total[0] = '\0';
    while (1) {
        size = getline(&line, &len, fd);
        if (size <= 0)
            break;
        tmp = total;
        tmp2 = my_strcat(" ", line);
        total = my_strcat(total, tmp2) - return_free(tmp) - return_free(tmp2);
    }
    free(line);
    fclose(fd);
    return total;
}

char **get_content(char *path)
{
    char *str = get_file(path);
    char **tab = my_split(str, "\n");
    return (tab);
}

int print_menu(void)
{
    char *str = get_file("menuscreen");
    char **tab = my_split(str, "\n");
    int starty = LINES / 3;
    int length = my_boostlen(tab[0]) / 3 + 10;

    clear();
    for (int i = 0; tab[i]; i++) {
        mvprintw(starty + i, COLS / 2 - length / 2, "%s", tab[i]);
    }
    mvprintw(LINES / 2, COLS / 2 - 14, "press any key to continue...");
    refresh();
    getch();
    return (print_selection(tab));
}

void print_title(char **title)
{
    int starty = LINES / 3;
    int length = my_boostlen(title[0]) / 3 + 10;

    for (int i = 0; title[i]; i++) {
        mvprintw(starty + i, COLS / 4 - length / 2, "%s", title[i]);
    }
}

void print_champs(champ_t *list, int champ_number)
{
    for (int i = 0; list[i].check == 0; i++) {
        if (list[i].selected == 1)
            attron(COLOR_PAIR(champ_number % 6 + 11));
        mvprintw(i / 6 * 4 + LINES / 5, i % 6 * COLS / 6 + 10, "%s", list[i].name);
        attroff(COLOR_PAIR(champ_number % 6 + 11));
    }
    mvprintw(LINES - 1, COLS / 2 - 28, "Press enter to select champion or 'x' to enter the arena");
}

int print_selection(char **title)
{
    int champ_number = 1;
    char **argv = malloc((21) * sizeof(char *));
    int i = 1;
    int cursor = 0;

    argv[0] = my_strdup("corewar");
    while (i < 20) {
        argv[i] = my_strdup(select_champ(champ_number++, &cursor));
        if (argv[i] == NULL)
            return (vm(i, argv));
        i++;
    }
    argv[i] = NULL;
    return (vm(i, argv));
}

char *select_champ(int i, int *cursor)
{
    champ_t *list = get_list_of_champions();
    char *name;
    int ind = 0;
    int len = 0;
    list[*cursor].selected = 1;
    for (len = 0; list[len].check == 0; len++);
    clear();
    mvprintw(1, COLS / 2 - 12, "Choose champion number %d", i);
    print_champs(list, i);
    refresh();
    while (1) {
        ind = getch();
        if (ind == 'x')
            return (NULL);
        if (ind == '\n')
            return (my_strcat("champions/", list[*cursor].name));
        list[*cursor].selected = 0;
        switch (ind) {
            case (KEY_UP):
                if (*cursor > 5)
                    *cursor -= 6;
                break;
            case (KEY_DOWN):
                if (*cursor + 6 < len)
                    *cursor += 6;
                break;
            case (KEY_LEFT):
                if (*cursor > 0 && *cursor % 6 != 0)
                    *cursor -= 1;
                break;
            case (KEY_RIGHT):
                if (*cursor + 1 < len && (*cursor + 1) % 6 != 0)
                    *cursor += 1;
                break;
        }
        list[*cursor].selected = 1;
        print_champs(list, i);
        refresh();
    }
    free(list);
}

int print_win_screen(corewar_t *glob)
{
    char **tab = get_content("endscreen");
    int starty = 10;
    int length = my_boostlen(tab[0]) / 3 + 10;
    int i = 0;

    clear();
    for (i = 0; tab[i]; i++) {
        mvprintw(starty + i, COLS / 2 - length / 2, "%s", tab[i]);
    }
    i = starty + 12;
    if (!glob->players) {
        mvprintw(i, COLS / 2 - my_strlen(glob->winner_name) / 2, "%s", glob->winner_name);
        mvprintw(i + 2, COLS / 2 - my_strlen(glob->winner_comment) / 2 - 1, "\"%s\"", glob->winner_comment);
    } else {
        mvprintw(i, COLS / 2 - my_strlen(glob->players->name) / 2, "%s", glob->players->name);
        mvprintw(i + 2, COLS / 2 - my_strlen(glob->players->comment) / 2 - 1, "\"%s\"", glob->players->comment);
    }
    refresh();
    getch();
    return (0);
}

void draw_arrow(int y, int x, char **tab)
{
    for (int i = 0; tab[i]; i++) {
        mvprintw(y + i, x, "%s", tab[i]);
    }
}

int print_speed_screen(corewar_t *glob)
{
    char **tab = get_content("speedscreen");
    char **arrow = get_content("arrow");
    int length = my_boostlen(tab[0]) / 3 + 10;
    int len2 = my_boostlen(arrow[0]) / 3 + 10;
    int ind = 0;
    int starty = 10;
    glob->speed = 3;

    while (1) {
        clear();
        for (int i = 0; tab[i]; i++) {
            mvprintw(starty + i, COLS / 2 - length / 2, "%s", tab[i]);
        }
        if (ind == '\n')
            return (0);
        if (ind == KEY_RIGHT && glob->speed < 5) {
            glob->speed++;
        }
        if (ind == KEY_LEFT && glob->speed > 1) {
            glob->speed--;
        }
        for (int i = 0; i < glob->speed; i++) {
            draw_arrow(LINES / 2, COLS / 2 - (len2 * glob->speed) / 2 + len2 * i, arrow);
        }
        refresh();
        ind = getch();
    }
}