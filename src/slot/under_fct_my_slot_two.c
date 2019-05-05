/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

chara_t init_null(void)
{
    chara_t ch;

    ch.body = NULL;
    ch.hair = NULL;
    ch.hat = NULL;
    ch.torso = NULL;
    ch.shoulder = NULL;
    ch.hands = NULL;
    ch.legs = NULL;
    ch.feet = NULL;
    return (ch);
}

void set_slot_game(game_t *gm, int destroy)
{
    if (gm->state == SLOT && destroy == 0) {
        gm->one = set_one_slot(gm->one, 0);
        gm->two = set_one_slot(gm->two, 1);
        gm->three = set_one_slot(gm->three, 2);
    }
}
