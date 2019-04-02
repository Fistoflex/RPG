/*
** EPITECH PROJECT, 2019
** init_struct_game
** File description:
** init_struct_game
*/

#include "my.h"

game_t init_struct_game(sfRenderWindow *window, sfVideoMode video_mode)
{
    game_t gm;

    gm.state = GAME;
    gm.sound = sfMusic_createFromFile("audio/sound.wav");
    gm.effect = FALSE;
    gm.mouse.moved.x = 0;
    gm.mouse.moved.y = 0;
    gm.key.esc = NOT_PUSHED;
    gm.key.left = NOT_PUSHED;
    gm.key.right = NOT_PUSHED;
    gm.key.up = NOT_PUSHED;
    gm.key.down = NOT_PUSHED;
    gm.clock.esc = sfClock_create();
    gm.game = my_create_sprite("picture/game.png", sfFalse);
    gm.setting = my_create_sprite("picture/setting.png", sfFalse);
    return (gm);
}
