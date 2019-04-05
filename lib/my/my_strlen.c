/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** do_the_strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
