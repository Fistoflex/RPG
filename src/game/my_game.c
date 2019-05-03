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
    //sfFloatRect rect = {0, 0, 1920, 1080};
    static int destroy = 0;

    if (gm->state == GAME && destroy == 0) {
        gm->clock.anim = sfClock_create();
        init_my_map(&gm->tiles);
        init_collision(&gm->colli);
        init_player_shape(&gm->hitbox, gm->chara.pos);
        gm->enemies = NULL;
        init_enemies(&gm->enemies);
        gm->clock.emi_clk = sfClock_create();
        gm->chara.pos.x = 2500;
        gm->chara.pos.y = 2500;
    }
    if (gm->state == GAME) {
        draw_hp(wind, gm->chara.stat->hp);
        my_map(wind, gm);
        collision(gm);
        attack_player(gm->enemies, &gm->hitbox, gm->clock.emi_clk);
        draw_enemies(wind, gm->enemies);
        move_player(wind, gm);
        draw_player_shape(wind, &gm->hitbox, gm->chara.pos);
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
        destroy_player_shape(gm->hitbox);
        destroy_enemies(gm->enemies);
        gm->clock.anim = NULL;
        sfClock_destroy(gm->clock.emi_clk);
        destroy = 0;
    }
}
