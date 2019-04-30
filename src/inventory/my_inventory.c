/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

int disp_elm(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {3, 3};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
        return (TRUE);
    }
    return (FALSE);
}

void draw_txt(sfRenderWindow *wind, text_t txt)
{
    sfRenderWindow_drawRectangleShape(wind, txt.shape, NULL);
    sfRenderWindow_drawText(wind, txt.name, NULL);
    sfRenderWindow_drawText(wind, txt.hp, NULL);
    sfRenderWindow_drawText(wind, txt.rank, NULL);
    sfRenderWindow_drawText(wind, txt.dmg, NULL);
    sfRenderWindow_drawText(wind, txt.dfs, NULL);
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

void my_inventory(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == INV && destroy == 0) {
        init_inventory(gm);
    }
    if (gm->state == INV) {
        sfRenderWindow_drawSprite(wind, gm->chara.bag.inv, NULL);
        draw_shape(gm->chara.bag.bag, wind);
        disp_player(wind, gm);
        dis_elem(wind, gm);
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