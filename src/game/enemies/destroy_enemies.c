/*
** EPITECH PROJECT, 2019
** destroy_enemies
** File description:
** destroy_enemies
*/

#include "my.h"

void destroy_enemies(list_emi_t *enemie)
{
    while (enemie != NULL) {
        sfCircleShape_destroy(enemie->enemie.circle.c);
        sfRectangleShape_destroy(enemie->enemie.shape.s);
        enemie = enemie->next;
    }
}