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

sfVector2f position(char *str)
{
    char **tab = my_str_to_word_array(str, ' ');
    sfVector2f pos = {atoi(tab[0]), atoi(tab[1])};

    return (pos);
}

void dis_elem(sfRenderWindow *wind, game_t *gm)
{
    bag_t *bag = gm->chara.bag.bag;

    bag->ps = position(gm->chara.bag.coord[0]);
    elem_to_disp(wind, &bag, gm->chara.hair, gm);
    elem_to_disp(wind, &bag, gm->chara.hat, gm);
    bag->ps = position(gm->chara.bag.coord[1]);
    elem_to_disp(wind, &bag, gm->chara.torso, gm);
    bag->ps = position(gm->chara.bag.coord[2]);
    elem_to_disp(wind, &bag, gm->chara.legs, gm);
    bag->ps = position(gm->chara.bag.coord[3]);
    elem_to_disp(wind, &bag, gm->chara.feet, gm);
    bag->ps = position(gm->chara.bag.coord[4]);
    elem_to_disp(wind, &bag, gm->chara.hands, gm);
}