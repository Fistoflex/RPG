/*
** EPITECH PROJECT, 2019
** color_txt_menu
** File description:
** color_txt_menu
*/

#include "my.h"

int my_set_the_new_scene(int push, game_t *gm, int stat)
{
    if (push == TRUE) {
        gm->state = stat;
        push = FALSE;
    }
    return (push);
}

void color_txt_start(game_t *gm)
{
    static int sound = FALSE;
    static int push = FALSE;
    sfFloatRect rect;
    float x = gm->menu.start.pos.x - 10;
    float y = gm->menu.start.pos.y - 10;

    biggest_txt(&gm->menu.start, x, y);
    rect = sfText_getGlobalBounds(gm->menu.start.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->menu.start.txt, sfYellow);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, CHOICE);
        sfText_setColor(gm->menu.start.txt, sfRed);
        sound = FALSE;
    }
}

void color_txt_exit(game_t *gm)
{
    static int sound = FALSE;
    static int push = FALSE;
    sfFloatRect rect;
    float x = gm->menu.exit.pos.x - 10;
    float y = gm->menu.exit.pos.y - 10;

    biggest_txt(&gm->menu.exit, x, y);
    rect = sfText_getGlobalBounds(gm->menu.exit.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->menu.exit.txt, sfYellow);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, EXIT);
        sfText_setColor(gm->menu.exit.txt, sfRed);
        sound = FALSE;
    }
}

void color_txt_setg(game_t *gm)
{
    static int sound = FALSE;
    sfFloatRect rect;
    static int push = FALSE;
    float x = gm->menu.setg.pos.x - 10;
    float y = gm->menu.setg.pos.y - 10;

    biggest_txt(&gm->menu.setg, x, y);
        rect = sfText_getGlobalBounds(gm->menu.setg.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->menu.setg.txt, sfYellow);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, SETG);
        sfText_setColor(gm->menu.setg.txt, sfRed);
        sound = FALSE;
    }
}
