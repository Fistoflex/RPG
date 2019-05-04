/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

void display_inventory(sfRenderWindow *wind, game_t *gm)
{
    sfRenderWindow_drawSprite(wind, gm->chara.bag.inv, NULL);
    draw_shape(gm->chara.bag.bag, wind);
    disp_player(wind, gm);
    dis_elem(wind, gm);
    disp_bag(wind, gm);
    drag_and_drop(wind, gm);
}
