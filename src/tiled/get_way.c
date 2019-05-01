/*
** EPITECH PROJECT, 2019
** get_way
** File description:
** get way ptr
*/

#include "my.h"

int get_north(int p_pos, int width)
{
    return (p_pos - width);
}

int get_south(int p_pos, int width)
{
    return (p_pos + width);
}

int get_est(int p_pos, int width)
{
    return (p_pos + 1);
}

int get_west(int p_pos, int width)
{
    return (p_pos - 1);
}