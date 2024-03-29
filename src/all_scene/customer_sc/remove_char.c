/*
** EPITECH PROJECT, 2019
** remove char
** File description:
** remove a char from a string for prompt function
*/

#include "my.h"

char *remove_char(char *str)
{
    int x = 0;
    char *res = NULL;
    int i = 0;
    static int n = 0;

    n = (n == 0) ? 1 : 0;
    if (str != NULL && str[0] != '\0') {
        i = my_strlen(str);
        res = malloc(sizeof(char) * (i +1));
        while (x < i - 1) {
            res[x] = str[x];
            x++;
        }
        res[x] = '\0';
        return (res);
    }
    return (str);
}
