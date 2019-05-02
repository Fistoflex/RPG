/*
** EPITECH PROJECT, 2019
** create_enemies
** File description:
** create enemies
*/

#include "my.h"

rect_shape_t init_shape(sfVector2f size, sfVector2f pos, sfColor color)
{
    rect_shape_t shape;

    shape.s = sfRectangleShape_create();
    sfRectangleShape_setSize(shape.s, size);
    shape.size = size;
    sfRectangleShape_setPosition(shape.s, pos);
    shape.pos = pos;
    sfRectangleShape_setFillColor(shape.s, color);
    shape.color = color;
    return (shape);
}

void init_enemies(emi_t *emi)
{
    emi->shape = init_shape(set_2f(50, 50), set_2f(1000, 200), sfRed);
}