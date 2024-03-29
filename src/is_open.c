/*
** EPITECH PROJECT, 2019
** is_open
** File description:
** is_open
*/

#include "my.h"

void is_open(sfRenderWindow *window, game_t gm, list_t *list)
{
    sfEvent event;

    gm.custom_step = NAME;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_event(window, event, &gm);
        all_scene(window, &gm, &list, &event);
        if (gm.state == GAME)
            find_the_bt_which_is_press(&gm, event);
        if (gm.state == EXIT)
            sfRenderWindow_close(window);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}
