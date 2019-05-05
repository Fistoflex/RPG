/*
** EPITECH PROJECT, 2019
** init_struct_game
** File description:
** init_struct_game
*/

#include "my.h"

game_t set_other(game_t gm)
{
    gm.tmp = malloc(sizeof((*gm.tmp)));
    gm.tmp->state = NONE;
    gm.clik = NOT_PUSHED;
    gm.state = SLOT;
    gm.sound = sfMusic_createFromFile("audio/sound.wav");
    gm.effect = FALSE;
    gm.mouse.moved.x = 0;
    gm.mouse.moved.y = 0;
    gm.mouse.release.x = 0;
    gm.mouse.release.y = 0;
    gm.chara.name = NULL;
    gm.key.esc = NOT_PUSHED;
    gm.key.left = NOT_PUSHED;
    gm.key.right = NOT_PUSHED;
    gm.key.up = NOT_PUSHED;
    gm.key.down = NOT_PUSHED;
    gm.key.enter = NOT_PUSHED;
    gm.key.back = NOT_PUSHED;
    gm.key.s_s = NOT_PUSHED;
    gm.key.s_d = NOT_PUSHED;
    return (gm);
}

game_t init_struct_game(void)
{
    game_t gm;

    gm = set_other(gm);
    gm.key.i = NOT_PUSHED;
    gm.view.menu = NULL;
    gm.view.pause = NULL;
    gm.view.game = NULL;
    gm.view.inv = NULL;
    gm.view.menu = set_view(gm.view.menu, 1.05);
    gm.view.game = set_view(gm.view.game, 0.6);
    gm.view.pause = set_view(gm.view.pause, 0.989);
    gm.view.inv = set_view(gm.view.inv, 1.05);
    gm.clock.esc = sfClock_create();
    gm.clock.enter = sfClock_create();
    gm.clock.spell = sfClock_create();
    gm.game = my_create_sprite("picture/game.png", sfFalse);
    gm.setting = my_create_sprite("picture/setting.png", sfFalse);
    return (gm);
}
