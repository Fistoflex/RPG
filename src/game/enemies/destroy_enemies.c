/*
** EPITECH PROJECT, 2019
** destroy_enemies
** File description:
** destroy_enemies
*/

#include "my.h"

void destroy_enemies(emi_t emi)
{
    sfCircleShape_destroy(emi.circle.c);
    sfRectangleShape_destroy(emi.shape.s);
}