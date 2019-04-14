/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    my_game(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == GAME && destroy == 0) {
        gm->chara.pos.x = 0; //pos chara
        gm->chara.pos.y = 0;
        gm->clock.anim = sfClock_create();
    }
    if (gm->state == GAME) {
        sfRenderWindow_drawSprite(wind, gm->game, NULL);
        move_player(wind, gm);
        destroy = 1;
    }
    if (gm->state != GAME && destroy == 1) {
        sfClock_destroy(gm->clock.anim);
        gm->clock.anim = NULL;
        destroy = 0;
    }
}
