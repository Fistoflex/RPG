/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** get player name
*/

#include "my.h"

void prompt(sfRenderWindow *window, game_t *gm, sfEvent evt) //tout se fait en deux fois -> étrange/20
{
    static char *tmp = NULL;

    find_the_bt_which_is_press(gm, evt);
    if (gm->key.enter == PUSHED) {
        gm->chara.name = tmp;
        gm->key.enter = NOT_PUSHED;
        printf("nae = %s\n ", gm->chara.name);
        return;
    } else if (gm->key.back == PUSHED) {
        tmp = remove_char(tmp);
        gm->key.back == NOT_PUSHED;
        return;
    }
    if (evt.type == sfEvtTextEntered && evt.text.unicode < 128) {
        /*if (my_strlen(tmp) <= 10)*/ printf("strlen de tmp = %d\n", my_strlen(tmp));
            tmp = add_char(tmp, evt.text.unicode);
    }
}