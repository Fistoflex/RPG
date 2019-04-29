/*
** EPITECH PROJECT, 2019
** get_tiles
** File description:
** read file
*/

#include "my.h"

char **get_file(char *filepath)
{
    char *line = NULL;
    size_t size = 0;
    FILE *fd = fopen(filepath, "r");
    char **dest = NULL;

    if (fd == NULL)
        return (NULL);
    getline(&line, &size, fd);
    line[my_strlen(line) - 1] = '\0';
    fclose(fd);
    dest = word_array(line, ',');
    free(line);
    return (dest);
}

int *get_tiles(char *filepath)
{
    char **tmp = get_file(filepath);
    int *dest = malloc(sizeof(int) * array_len(tmp));
    int i = 0;

    while (tmp[i] != NULL) {
        dest[i] = getnbr(tmp[i]) - 1;
        i++;
    }
    free_array(tmp);
    return (dest);
}