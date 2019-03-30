/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    my_game(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    // if (gm->state == GAME && destroy == 0) {
    //     gm->chara.pos.x = 0;
    //     gm->chara.pos.y = 0;
    //     gm->clock.anim = sfClock_create();
    //     gm->chara.body = my_create_sprite("picture/dark.png", sfFalse);
    //     gm->chara.hair = my_create_sprite("picture/hair.png", sfFalse);
    //     gm->chara.hat = NULL;
    //     gm->chara.torso = my_create_sprite("picture/chest_male.png", sfFalse);
    //     gm->chara.shoulder = my_create_sprite("picture/shoulders.png", sfFalse);
    //     gm->chara.hands = my_create_sprite("picture/hands.png", sfFalse);
    //     gm->chara.legs = my_create_sprite("picture/legs.png", sfFalse);
    //     gm->chara.feet = my_create_sprite("picture/feet.png", sfFalse);
    // }
    // if (gm->state == GAME) {
    //     sfRenderWindow_drawSprite(wind, gm->game, NULL);
    //     move_player(wind, gm);
    //     destroy = 1;
    // }
    if (gm->state != GAME && destroy == 1) {
        sfClock_destroy(gm->clock.anim);
        sfSprite_destroy(gm->chara.body);
    }
}
