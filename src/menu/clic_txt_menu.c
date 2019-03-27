/*
** EPITECH PROJECT, 2019
** clic_txt_menu
** File description:
** clic_txt_menu
*/

#include "my.h"

void clic_menu_exit(sfRenderWindow *wind, game_t *gm, sfVector2i but_pos)
{
    sfFloatRect rect;
    static int pressed = FALSE;

    rect = sfText_getGlobalBounds(gm->menu.exit.txt);
    if (sfFloatRect_contains(&rect, but_pos.x, but_pos.y))
        pressed = TRUE;
    if (pressed == TRUE && (but_pos.x == -10 && but_pos.y == -10)) {
        sfRenderWindow_close(wind);
        pressed = FALSE;
    }
}

void clic_menu_settings(game_t *gm, sfVector2i but_pos)
{
    sfFloatRect rect;
    static int pressed = FALSE;

    rect = sfText_getGlobalBounds(gm->menu.setg.txt);
    if (sfFloatRect_contains(&rect, but_pos.x, but_pos.y))
        pressed = TRUE;
    if (pressed == TRUE && (but_pos.x == -10 && but_pos.y == -10)) {
        gm->state = SETTINGS;
        pressed = FALSE;
    }
}