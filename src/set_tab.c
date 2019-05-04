/*
** EPITECH PROJECT, 2019
** set_tab
** File description:
** set_tab
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char **set_tab(char *path)
{
    int fd = open(path, O_RDONLY);
    char *line = NULL;
    int size = 0;
    char **tab = NULL;

    while (get_next_line(fd) != NULL)
        size++;
    close(fd);
    fd = open(path, O_RDONLY);
    tab = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while ((line = get_next_line(fd)) != NULL) {
        tab[size] = line;
        size++;
    }
    tab[size] = NULL;
    return (tab);
}
