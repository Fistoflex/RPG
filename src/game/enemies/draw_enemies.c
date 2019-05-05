/*
** EPITECH PROJECT, 2019
** draw_enemies
** File description:
** draw enemies
*/

#include "my.h"

void draw_one_enemie(sfRenderWindow *wind, emi_t emi)
{
    sfIntRect rect;

    sfCircleShape_setPosition(emi.circle.c, get_center(emi.shape, 200));
    emi.circle.pos = get_center(emi.shape, 200);
    rect = my_create_rect(50, 50, 0, 0);
    disp_my_wp(emi.sprite, emi.shape.pos, rect, wind);
}

void draw_enemies(sfRenderWindow *wind, list_emi_t *enemies)
{
    while (enemies != NULL) {
        if (enemies->enemie.state != DEF)
            draw_one_enemie(wind, enemies->enemie);
        enemies = enemies->next;
    }
}