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

circle_shape_t init_circle(float raduis, sfVector2f pos, sfColor color)
{
    circle_shape_t circle;

    circle.c = sfCircleShape_create();
    sfCircleShape_setRadius(circle.c, raduis);
    circle.raduis = raduis;
    sfCircleShape_setPosition(circle.c, pos);
    circle.pos = pos;
    sfCircleShape_setFillColor(circle.c, color);
    circle.color = color;
    return (circle);
}

sfVector2f get_center(rect_shape_t shape, float raduis)
{
    sfVector2f pos;

    pos.x = shape.pos.x - (raduis * 2 + 90);
    pos.y = shape.pos.y - (raduis * 2 + 90);
    return (pos);
}

emi_t set_up_enemie(int x, int y, game_t *gm)
{
    emi_t emi;

    emi.shape = init_shape(set_2f(25, 25), set_2f(x, y), sfRed);
    emi.circle = init_circle(500, get_center(emi.shape, 500), sfBlack);
    emi.st = init_stat(gm, "wolf");
    return (emi);
}

void init_enemies(list_emi_t **enemies, game_t *gm)
{
    put_in_enemies(enemies, set_up_enemie(3000, 3000, gm));
    put_in_enemies(enemies, set_up_enemie(3500, 3500, gm));
}