/*
** EPITECH PROJECT, 2018
** my_create_rect
** File description:
** create rect
*/

#include "my.h"

sfRectangleShape *my_create_shape(sfVector2f size, sfVector2f pos, sfColor color)
{
        sfRectangleShape *shape;

        shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(shape, pos);
        sfRectangleShape_setSize(shape, size);
        sfRectangleShape_setFillColor(shape, color);
        return (shape);
}