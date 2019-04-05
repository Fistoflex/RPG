/*
** EPITECH PROJECT, 2019
** find
** File description:
** find
*/

#include "my.h"
#include "pointer.h"

void    set_stat(int *button)
{
    (*button) = PUSHED;
}

void    unset_stat(int *button, int flag)
{
    if (flag != sfKeyEscape)
        (*button) = NOT_PUSHED;
}

void    find_the_bt(game_t *gm, sfEvent evt)
{
    int i = 0;
    key_s key[] = {{sfKeyEscape, &gm->key.esc, &set_stat},
                    {sfKeyLeft, &gm->key.left, &set_stat},
                    {sfKeyRight, &gm->key.right, &set_stat},
                    {sfKeyUp, &gm->key.up, &set_stat},
                    {sfKeyDown, &gm->key.down, &set_stat},
                    {sfKeyReturn, &gm->key.enter, &set_stat},
                    {sfKeyBack, &gm->key.back, &set_stat},
                    {'\0', '\0', NULL}};

    while (key[i].flag != '\0') {
        if (key[i].flag == evt.key.code)
            key[i].fct(key[i].button);
        i++;
    }
}

void    find_the_bt_which_is_press(game_t *gm, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed) {
        find_the_bt(gm, evt);
        sfClock_restart(gm->clock.esc);
    }
}
