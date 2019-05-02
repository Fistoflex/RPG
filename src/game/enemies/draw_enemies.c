/*
** EPITECH PROJECT, 2019
** draw_enemies
** File description:
** draw enemies
*/

#include "my.h"

void draw_enemies(sfRenderWindow *wind, emi_t *emi)
{
    sfCircleShape_setPosition(emi->circle.c, get_center(emi->shape, 200));
    emi->circle.pos = get_center(emi->shape, 200);
//    sfRenderWindow_drawCircleShape(wind, emi->circle.c, NULL);
    sfRenderWindow_drawRectangleShape(wind, emi->shape.s, NULL);
}