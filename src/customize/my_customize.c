/*
** EPITECH PROJECT, 2019
** cust
** File description:
** cust
*/

#include "my.h"

void my_customize(sfRenderWindow *wind, game_t *gm, list_t **list)
{
    static int choice = 0;

    if (gm->state == CHOICE && choice == 0) {
        if (gm->key.enter == PUSHED) {
            gm->state = NAME;
            gm->key.enter = NOT_PUSHED;
        }
        (*list) = make_your_choice(wind, gm, (*list));
    } else if (gm->state == NAME) {
        if (gm->key.enter == PUSHED) {
            gm->state = GAME;
            gm->key.enter = NOT_PUSHED;
        }
        save_my_choice(wind, (*list), gm);
        /* prompt function*/
        choice = 1;
    } else
        if (gm->state == CHOICE && choice == 1)
            gm->state = GAME;
}
