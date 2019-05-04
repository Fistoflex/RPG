/*
** EPITECH PROJECT, 2019
** draw_enemies
** File description:
** draw enemies
*/

#include "my.h"

void draw_one_enemie(sfRenderWindow *wind, emi_t emi)
{
    sfCircleShape_setPosition(emi.circle.c, get_center(emi.shape, 200));
    emi.circle.pos = get_center(emi.shape, 200);
    sfRenderWindow_drawRectangleShape(wind, emi.shape.s, NULL);
}

void draw_enemies(sfRenderWindow *wind, list_emi_t *enemies)
{
    while (enemies != NULL) {
        draw_one_enemie(wind, enemies->enemie);
        enemies = enemies->next;
    }
}