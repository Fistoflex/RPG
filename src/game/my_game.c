/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

sfView *set_view(sfView *view, float zoom)
{
    sfFloatRect rect = {0, 0, 1920, 1080};
    sfVector2f size = {1920, 1080};

    view = sfView_createFromRect(rect);
    sfView_setSize(view, size);
    sfView_zoom(view, zoom);
    return (view);
}

void    my_game(sfRenderWindow *wind, game_t *gm)
{
    sfFloatRect rect = {0, 0, 1920, 1080};
    static int destroy = 0;

    if (gm->state == GAME && destroy == 0) {
        gm->clock.anim = sfClock_create();
    }
    if (gm->state == GAME) {
        sfRenderWindow_drawSprite(wind, gm->game, NULL);
        move_player(wind, gm);
        if (gm->key.i == PUSHED) {
            gm->state = INV;
            gm->key.i = NOT_PUSHED;
        }
        sfView_setCenter(gm->view.game, gm->chara.pos);
        sfRenderWindow_setView(wind, gm->view.game);
        destroy = 1;
    }
    if (gm->state != GAME && destroy == 1) {
        sfClock_destroy(gm->clock.anim);
        gm->clock.anim = NULL;
        destroy = 0;
    }
}
