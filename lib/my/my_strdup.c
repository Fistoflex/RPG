/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** do_the_strdup
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
