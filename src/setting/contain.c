/*
** EPITECH PROJECT, 2019
** contain
** File description:
** contain
*/

#include "my.h"

int contain(sfRenderWindow *win, int pressed, game_t *gm, settings_t set)
{
    sfVector2i mouse = gm->mouse.button;
    sfFloatRect rect;

    if (pressed == FALSE) {
        rect = sfRectangleShape_getGlobalBounds(set.rect);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
            sfRenderWindow_drawText(win, set.txt, NULL);
            pressed = TRUE;
        }
    }
    return (pressed);
}