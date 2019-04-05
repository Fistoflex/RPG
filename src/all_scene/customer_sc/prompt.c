/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** get player name
*/

#include "my.h"

void prompt(sfEvent evt, game_t *gm)
{
    static char *tmp = NULL;

    find_the_bt_which_is_press(gm, evt);
    if (gm->key.enter == PUSHED) {
        gm->chara.name = tmp;
        gm->key.enter = NOT_PUSHED;
        return;
    } else if (gm->key.back == PUSHED) {
        tmp = remove_char(tmp);
        gm->key.back == NOT_PUSHED;
        return;
    }
    if (evt.type == sfEvtTextEntered && evt.text.unicode < 128) {
        if (my_strlen(tmp) <= 10)
            tmp = add_char(tmp, evt.text.unicode);
    }
}