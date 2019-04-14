/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read_file
*/

#include "my.h"

char **read_file(char *path)
{
    FILE *fd = fopen(path, "r");
    char *str = NULL;
    char *line = NULL;
    size_t len = 0;
    int x = 0;
    int cpt = 0;
    char **tab = NULL;

    for (; getline(&line, &len, fd) != -1; cpt++);
    fclose(fd);
    fd =  fopen(path, "r");
    tab = malloc(sizeof(char *) * (cpt + 1));
    while (getline(&line, &len, fd) != -1) {
        tab[x] = my_strdup(line, FREE);
        tab[x] = my_epurstr(tab[x], "\n", FREE);
        line = NULL;
        x++;
    }
    tab[x] = NULL;
    for (x = 0; tab[x] != NULL; x++);
    if (x - 1 > 0 && tab[x - 1][0] == 0)
        tab[x] = NULL;
    return (tab);
}
