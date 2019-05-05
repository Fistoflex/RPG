/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

void head(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.hair, KEEP);
        item->sp = sprite_copy(item->path, item->pos);
    } else if (state == 1) {
        gm->chara.path.hair = my_strdup(item->path, KEEP);
        gm->chara.hair = sprite_copy(gm->chara.path.hair, item->pos);
    }
}

void torso(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.torso, KEEP);
        item->sp = sprite_copy(item->path, item->pos);
    } else if (state == 1) {
        gm->chara.path.torso = my_strdup(item->path, KEEP);
        gm->chara.torso = sprite_copy(gm->chara.path.torso, item->pos);
    }
}

void pants(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.legs, KEEP);
        item->sp = sprite_copy(item->path, item->pos);
    } else if (state == 1) {
        gm->chara.path.legs = my_strdup(item->path, KEEP);
        gm->chara.legs = sprite_copy(gm->chara.path.legs, item->pos);
    }
}

void feet(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.feet, KEEP);
        item->sp = sprite_copy(item->path, item->pos);
    } else if (state == 1) {
        gm->chara.path.feet = my_strdup(item->path, KEEP);
        gm->chara.feet = sprite_copy(gm->chara.path.feet, item->pos);
    }
}

void hand(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.hands, KEEP);
        item->sp = sprite_copy(item->path, item->pos);
    } else if (state == 1) {
        gm->chara.path.hands = my_strdup(item->path, KEEP);
        gm->chara.hands = sprite_copy(gm->chara.path.hands, item->pos);
    }
}