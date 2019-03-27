/*
** EPITECH PROJECT, 2019
** effect
** File description:
** effect
*/

#include "my.h"

void resume_effect(game_t *gm)
{
    sfFloatRect rect;
    float x = gm->pause.resume.pos.x - 10;
    float y = gm->pause.resume.pos.y - 10;
    static int sound = FALSE;
    static int push = FALSE;

    biggest_txt(&gm->pause.resume, x, y);
    rect = sfText_getGlobalBounds(gm->pause.resume.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->pause.resume.txt, sfRed);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, GAME);
        sfText_setColor(gm->pause.resume.txt, sfGreen);
        sound = FALSE;
    }
}

void home_effect(game_t *gm)
{
    sfFloatRect rect;
    float x = gm->pause.home.pos.x - 10;
    float y = gm->pause.home.pos.y - 10;
    static int sound = FALSE;
    static int push = FALSE;

    biggest_txt(&gm->pause.home, x, y);
    rect = sfText_getGlobalBounds(gm->pause.home.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->pause.home.txt, sfGreen);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, MENU);
        sfText_setColor(gm->pause.home.txt, sfYellow);
        sound = FALSE;
    }
}

void exit_effect(game_t *gm)
{
    sfFloatRect rect;
    float x = gm->pause.exit.pos.x - 10;
    float y = gm->pause.exit.pos.y - 10;
    static int sound = FALSE;
    static int push = FALSE;

    biggest_txt(&gm->pause.exit, x, y);
    rect = sfText_getGlobalBounds(gm->pause.exit.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->pause.exit.txt, sfGreen);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, EXIT);
        sfText_setColor(gm->pause.exit.txt, sfRed);
        sound = FALSE;
    }
}

void restart_effect(game_t *gm)
{
    sfFloatRect rect;
    float x = gm->pause.restart.pos.x - 10;
    float y = gm->pause.restart.pos.y - 10;
    static int sound = FALSE;
    static int push = FALSE;

    biggest_txt(&gm->pause.restart, x, y);
    rect = sfText_getGlobalBounds(gm->pause.restart.txt);
    if (sfFloatRect_contains(&rect, gm->mouse.button.x, gm->mouse.button.y)) {
        sfText_setColor(gm->pause.restart.txt, sfGreen);
        if (sound == FALSE) {
            sfMusic_play(gm->sound);
            sound = TRUE;
        }
        push = TRUE;
    } else {
        push = my_set_the_new_scene(push, gm, GAME);
        sfText_setColor(gm->pause.restart.txt, sfBlue);
        sound = FALSE;
    }
}
