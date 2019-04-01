/*
** EPITECH PROJECT, 2019
** add char
** File description:
** add char at end of a str
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "my.h"

char *add_char(char *str, char c)
{
    int i = 0;
    char *res = NULL;

    if (str != NULL && str[0] != '\0') {
        res = malloc(sizeof(char) * (strlen(str) + 2));
        while (str[i] != '\0') {
            res[i] = str[i];
            i++;
        }
        res[i] = c;
        res[i + 1] = '\0';
    }
    else {
        res = malloc(sizeof(char) * 2);
        res[0] = c;
        res[1] = '\0';
    }
    return (res);
}