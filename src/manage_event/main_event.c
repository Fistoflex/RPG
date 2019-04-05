/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include "my.h"

void manage_event(sfRenderWindow *window, sfEvent evt, game_t *gm)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (gm->custom_step == NAME)
        prompt(evt, gm);
    get_mouse_pos(gm, evt);
    find_the_bt_which_is_press(gm, evt);
}
