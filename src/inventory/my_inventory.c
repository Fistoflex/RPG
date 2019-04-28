/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    my_inventory(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == INV && destroy == 0) {
        init_inventory(gm);
    }
    if (gm->state == INV) {
        sfRenderWindow_drawSprite(wind, gm->chara.bag.inv, NULL);
        if (gm->key.i == PUSHED) {
            gm->state = GAME;
            gm->key.i = NOT_PUSHED;
        }
        sfRenderWindow_setView(wind, gm->view.inv);
        destroy = 1;
    }
    if (gm->state != INV && destroy == 1) {
        sfSprite_destroy(gm->chara.bag.inv);
        destroy = 0;
    }
}