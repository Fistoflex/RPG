/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "pointer.h"
#include "my.h"

void    draw_shape(bag_t *bag, sfRenderWindow *wind)
{
    while (bag != NULL) {
        sfRectangleShape_setPosition(bag->shape, bag->pos);
        sfRenderWindow_drawRectangleShape(wind, bag->shape, NULL);
        bag = bag->next;
    }
}

void elem_to_disp(sfRenderWindow *wind, bag_t **bag, sfSprite *sp, game_t *gm)
{
    sfIntRect rect = {0, 654, 64, 50};
    sfFloatRect rec;

    if (sp != NULL)
        rec = sfRectangleShape_getGlobalBounds((*bag)->shape);
    if (disp_elm(wind, sp, rect, (*bag)->ps) == TRUE) {
        if (sp != NULL && sfFloatRect_contains(&rec, gm->mouse.moved.x,
        gm->mouse.moved.y))
            draw_txt(wind, (*bag)->txt);
        (*bag) = (*bag)->next;
    }
}

void    my_inventory(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;
    sfFloatRect rect = {0, 0, 1920, 1080};

    if (gm->state == INV && destroy == 0) {
        init_inventory(gm);
    }
    if (gm->state == INV) {
        sfRenderWindow_drawSprite(wind, gm->chara.bag.inv, NULL);
        draw_shape(gm->chara.bag.bag, wind);
        disp_player(wind, gm);
        dis_elem(wind, gm);
        disp_bag(wind, gm);
        drag_and_drop(wind, gm);
        if (gm->key.i == PUSHED) {
            gm->state = GAME;
            gm->key.i = NOT_PUSHED;
        }
        sfView_reset(gm->view.inv, rect);
        sfRenderWindow_setView(wind, gm->view.inv);
        destroy = 1;
    }
    if (gm->state != INV && destroy == 1) {
        sfSprite_destroy(gm->chara.bag.inv);
        destroy = 0;
    }
}