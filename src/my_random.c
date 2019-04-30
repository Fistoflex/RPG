/*
** EPITECH PROJECT, 2019
** my_random
** File description:
** my_random
*/

#include "my.h"

int my_random(int max)
{
    int res = 0;

    res = rand() % max;
    return (res);
}