/*
** EPITECH PROJECT, 2019
** esc
** File description:
** esc
*/

#include "pointer.h"
#include "my.h"

void    bt_esc_redirect(game_t *gm)
{
    int i = 0;
    stat_scn_t scene[] = {{GAME, PAUSE}, {PAUSE, GAME}, {SETG, MENU},
                          {MENU, MENU}, {SLOT, MENU}, {-1, -1}};

    if (gm->key.esc == PUSHED) {
        while (scene[i].scene != gm->state && scene[i].scene != -1)
            i++;
        if (scene[i].scene != -1)
            gm->state = scene[i].new_scene;
        gm->key.esc = NOT_PUSHED;
    }
}
