/*
** EPITECH PROJECT, 2019
** scene
** File description:
** scene
*/

#include "my.h"

void all_scene(sfRenderWindow *window, game_t *gm, list_t **list)
{
    my_intro(window, gm);
    bt_esc_redirect(gm);
    my_menu(window, gm);
    keyboard_guide(window, gm);
    my_setting(window, gm);
    my_pause(window, gm);
    my_game(window, gm);
    my_setting(window, gm);
    my_customize(window, gm, list);
    my_slot(window, gm);
}
