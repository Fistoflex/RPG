/*
** EPITECH PROJECT, 2019
** add char
** File description:
** add char at end of a str
*/

#include "my.h"

char *add_char(char *str, char c)
{
    int i = 0;
    char *res = NULL;
    static int n = 0;

    if (n == 0 && str != NULL && str[0] != '\0') {
        res = malloc(sizeof(char) * (my_strlen(str) + 2));
        while (str[i] != '\0') {
            res[i] = str[i];
            i++;
        }
        res[i] = c;
        res[i + 1] = '\0';
    } else {
        if (n == 0) {
            res = malloc(sizeof(char) * 2);
            res[0] = c;
            res[1] = '\0';
        }
    }
    n = (n == 0) ? 1 : 0;
    if (n == 0)
        return (res);
    return (str);
}
