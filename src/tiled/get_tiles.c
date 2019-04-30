/*
** EPITECH PROJECT, 2019
** get_tiles
** File description:
** read file
*/

#include "my.h"
#include <string.h>

char **get_file(char *filepath)
{
    char *line = NULL;
    size_t size = 0;
    FILE *fd = fopen(filepath, "r");
    char *tmp = my_strdup("", KEEP);

    if (fd == NULL)
        return (NULL);
    while (getline(&line, &size, fd) != -1) {
        line[my_strlen(line) - 1] = '\0';
        tmp = my_strcat(tmp, line, KEEP, KEEP);
    }
    fclose(fd);
    return(word_array(tmp, ','));
}

int *get_tiles(char *filepath)
{
    char **tmp = get_file(filepath);
    int *dest = malloc(sizeof(int) * array_len(tmp));
    int i = 0;

    while (tmp[i] != NULL) {
        dest[i] = getnbr(tmp[i]) - 1;
        if (dest[i] < 0)
            dest[i] = 0;
        i++;
    }
    free_array(tmp);
    return (dest);
}