/*
** EPITECH PROJECT, 2019
** word_array
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>

int get_array_lenght(char *str, char c)
{
    int i = 0;
    int tmp = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            tmp++;
        i++;
    }
    return (tmp + 1);
}

int get_str_lenght(char *str, int i, char c)
{
    int tmp = 0;

    while (str[i] != '\0' && str[i] != c) {
        i++;
        tmp++;
    }
    return (tmp);
}

char **word_array(char *str, char c)
{
    char **dest = malloc(sizeof(char *) * (get_array_lenght(str, c) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    dest[j] = malloc(sizeof(char *) * (get_str_lenght(str, i, c) + 1));
    while (str[i] != '\0') {
        if (str[i] != '\0' && str[i] == c) {
            dest[j++][k] = '\0';
            i++;
            dest[j] = malloc(sizeof(char *) * (get_str_lenght(str, i, c) + 1));
            k = 0;
            continue;
        }
        dest[j][k++] = str[i++];
    }
    dest[j++][k] = '\0';
    dest[j] = NULL;
    return (dest);
}