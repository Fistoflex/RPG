/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

text_t copy_txt(text_t txt)
{
    text_t text;

    text.name = txt.name;
    text.hp = txt.hp;
    text.rank = txt.rank;
    text.dmg = txt.dmg;
    text.dfs = txt.dfs;
    text.shape = txt.shape;
    return (text);
}

itm_t copy_itm(itm_t itm)
{
    itm_t item;

    item.pos.x = 0;
    item.pos.y = 0;
    item.path = my_strdup(itm.path, KEEP);
    item.sp = item.sp;
    item.tab = NULL;
    item.txt = copy_txt(itm.txt);
    return (item);
}

void copy_struct(bag_t **bag, game_t *gm)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 0);
    int n = (*bag)->state;

    gm->tmp = malloc(sizeof((*gm->tmp)));
    gm->tmp->state = n;
    gm->tmp->ps.x = 0;
    gm->tmp->ps.y = 0;
    gm->tmp->itm = copy_itm((*bag)->itm);
    (*bag)->itm.sp = NULL;
    gm->tmp->shape = (*bag)->shape;
    //sfRectangleShape_setFillColor((*bag)->shape, color);
}