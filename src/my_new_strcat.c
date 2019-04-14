/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** str
*/

#include "my.h"

char    *cpy_str_(char *dest, char *src, char *str, int fre)
{
    int    i = 0;
    int    x = 0;

    for (i = 0; dest != NULL && dest[i] != '\0'; i++) {
        str[x] = dest[i];
        x++;
    }
    for (i = 0; src[i] != '\0'; i++) {
        str[x] = src[i];
        x++;
    }
    str[x] = '\0';
    if (fre == FREE)
        free(dest);
    return (str);
}

char    *my_new_strcat(char *dest, char *src, int x, int fre)
{
    char    *str = NULL;

    if (dest == NULL)
        return (my_strdup(src, KEEP));
    x += my_strlen(src);
    str = malloc(sizeof(char) * (x + 1));
    if (dest == NULL || src == NULL)
        return (NULL);
    else
        return (cpy_str_(dest, src, str, fre));
}
