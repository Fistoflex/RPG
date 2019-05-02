/*
** EPITECH PROJECT, 2019
** draw_enemies
** File description:
** draw enemies
*/

#include "my.h"

void draw_enemies(sfRenderWindow *wind, emi_t *emi)
{
    sfRenderWindow_drawRectangleShape(wind, emi->shape.s, NULL);
}