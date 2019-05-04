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
        item->sp = gm->chara.hair;
    } else if (state == 1) {
        gm->chara.path.hair = my_strdup(item->path, KEEP);
        gm->chara.hair = item->sp;
    }
}

void torso(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.torso, KEEP);
        item->sp = gm->chara.torso;
    } else if (state == 1) {
        gm->chara.path.torso = my_strdup(item->path, KEEP);
        gm->chara.torso = item->sp;
    }
}

void pants(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.legs, KEEP);
        item->sp = gm->chara.legs;
    } else if (state == 1) {
        gm->chara.path.legs = my_strdup(item->path, KEEP);
        gm->chara.legs = item->sp;
    }
}

void feet(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.feet, KEEP);
        item->sp = gm->chara.feet;
    } else if (state == 1) {
        gm->chara.path.feet = my_strdup(item->path, KEEP);
        gm->chara.feet = item->sp;
    }
}

void hand(game_t *gm, itm_t *item, int state)
{
    if (state == 0) {
        item->path = my_strdup(gm->chara.path.hands, KEEP);
        item->sp = gm->chara.hands;
    } else if (state == 1) {
        gm->chara.path.hands = my_strdup(item->path, KEEP);
        gm->chara.hands = item->sp;
    }
}