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
    //    all_scene(window, &gm, &list);
        if (gm.state == EXIT)
            sfRenderWindow_close(window);
        if (gm.chara.name != NULL)
            printf("name = %s\n", gm.chara.name);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfWhite);
    }
}
