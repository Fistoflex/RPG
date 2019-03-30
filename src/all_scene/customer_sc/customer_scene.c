/*
** EPITECH PROJECT, 2019
** customer_scene
** File description:
** custome you champion
*/

#include "my.h"

void make_your_choise(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    static sfIntRect rect;

    if (gm->key.left == PUSHED) {
        press_left(wind, gm, list->iteme);
        gm->key.left = NOT_PUSHED;
    }
    if (gm->key.right == PUSHED) {
        press_right(wind, gm, list->iteme);
        gm->key.right = NOT_PUSHED;
    }
    if (gm->key.up == PUSHED) {
        press_top(wind, gm, list);
        gm->key.up = NOT_PUSHED;
    }
    if (gm->key.down == PUSHED) {
        press_bot(wind, gm, list);
        gm->key.down = NOT_PUSHED;
    }
}

//fonction qui affiche en petit, grand, change les coord en fonction
list_t **init_my_choice()
{
    int n = 0;
    list_t *list = NULL;
    choice_t *hat = NULL;
    choice_t *hair = NULL;
    choice_t *top = NULL;
    choice_t *bot = NULL;

    for (n = 0; n != 3; n++)
        hat = malloc_my_link_choice(hat, )
}
//top choice , mid, bot
//valider -> parcoure toute les listes, et check state_iteme*
