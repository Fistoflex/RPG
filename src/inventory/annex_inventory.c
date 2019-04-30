/*
** EPITECH PROJECT, 2019
** annex inventory
** File description:
** annex_inventory
*/

#include "my.h"

void draw_shape(bag_t *bag, sfRenderWindow *wind)
{
    while (bag != NULL) {
        sfRenderWindow_drawRectangleShape(wind, bag->shape, NULL);
        bag = bag->next;
    }
}

void disp_pl(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {7, 7};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
    }
}

void disp_player(sfRenderWindow *wind, game_t *gm)
{
    sfIntRect rect = {0, 654, 64, 50};
    sfVector2f pos = {490, 74};

    disp_pl(wind, gm->chara.body, rect, pos);
    disp_pl(wind, gm->chara.hair, rect, pos);
    disp_pl(wind, gm->chara.hat, rect, pos);
    disp_pl(wind, gm->chara.torso, rect, pos);
    disp_pl(wind, gm->chara.shoulder, rect, pos);
    disp_pl(wind, gm->chara.hands, rect, pos);
    disp_pl(wind, gm->chara.legs, rect, pos);
    disp_pl(wind, gm->chara.feet, rect, pos);
}