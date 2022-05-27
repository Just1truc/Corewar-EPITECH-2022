/*
** EPITECH PROJECT, 2021
** champ
** File description:
** corewar
*/

#include "header.h"

int dirlen(char *name)
{
    int len = 0;
    DIR *dd;

    dd = opendir(name);
    while (readdir(dd) != NULL)
        len++;
    closedir(dd);
    return (len);
}

int is_cor(char *name)
{
    int len = my_strlen(name);

    if (len < 4)
        return (0);
    if (name[len - 4] == '.' && name[len - 3] == 'c' && name[len - 2] == 'o' && name[len - 1] == 'r')
        return (1);
    return (0);
}

champ_t *get_list_of_champions(void)
{
    DIR *dd;
    struct dirent *dir;
    champ_t *list;
    int len = dirlen("champions");
    int i = 0;

    list = malloc((len + 1) * sizeof(champ_t));
    dd = opendir("champions");
    while ((dir = readdir(dd)) != NULL) {
        if (is_cor(dir->d_name) == 1) {
            list[i].name = my_strdup(dir->d_name);
            list[i].selected = 0;
            list[i].check = 0;
            i++;
        }
    }
    closedir(dd);
    list[i].check = 1;
    return (list);
}