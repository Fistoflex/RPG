/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** do_the_strdup
*/

#include <stdlib.h>

char my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
