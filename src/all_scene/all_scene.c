/*
** EPITECH PROJECT, 2019
** scene
** File description:
** scene
*/

#include "my.h"

void all_scene(sfRenderWindow *window, game_t *gm, list_t **list, sfEvent *evt)
{
    my_intro(window, gm);
    bt_esc_redirect(gm);
    my_menu(window, gm);
    my_setting(window, gm);
    my_pause(window, gm);
    my_game(window, gm);
    my_setting(window, gm);
    my_customize(window, gm, list, evt);
    my_slot(window, gm);
}
