/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    my_game(sfRenderWindow *wind, game_t *gm)
{
    if (gm->state == GAME)
        sfRenderWindow_drawSprite(wind, gm->game, NULL);
}