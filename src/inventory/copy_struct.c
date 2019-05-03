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

    text.name = text_copy(txt.name);
    sfText_destroy(txt.name);
    text.hp = text_copy(txt.hp);
    sfText_destroy(txt.hp);
    text.rank = text_copy(txt.rank);
    sfText_destroy(txt.rank);
    text.dmg = text_copy(txt.dmg);
    sfText_destroy(txt.dmg);
    text.dfs = text_copy(txt.dfs);
    sfText_destroy(txt.dfs);
    text.shape = shape_copy(txt.shape);
    sfRectangleShape_destroy(txt.shape);
    return (text);
}

itm_t copy_itm(itm_t itm)
{
    itm_t item;

    item.pos.x = 0;
    item.pos.y = 0;
    item.path = my_strdup(itm.path, KEEP);
    sfSprite_destroy(itm.sp);
    item.sp = sprite_copy(item.path, item.pos);
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
    gm->tmp->shape = shape_copy((*bag)->shape);
    sfRectangleShape_setFillColor((*bag)->shape, color);
}