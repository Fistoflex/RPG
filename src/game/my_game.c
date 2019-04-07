/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    my_game(sfRenderWindow *wind, game_t *gm, list_t **list)
{
    static int destroy = 0;
    static int step = 0;

    // if (gm->state == GAME && destroy == 0) {
    //     gm->chara.pos.x = 0;
    //     gm->chara.pos.y = 0;
    //     gm->clock.anim = sfClock_create();
    //     gm->chara.body = my_create_sprite("picture/dark.png", sfFalse);
    //     gm->chara.hair = NULL; //my_create_sprite("picture/hair.png", sfFalse);
    //     gm->chara.hat = NULL;
    //     gm->chara.torso = NULL; //my_create_sprite("picture/chest_male.png", sfFalse);
    //     gm->chara.shoulder = NULL; //my_create_sprite("picture/shoulders.png", sfFalse);
    //     gm->chara.hands = NULL; //my_create_sprite("picture/hands.png", sfFalse);
    //     gm->chara.legs = NULL; //my_create_sprite("picture/legs.png", sfFalse);
    //     gm->chara.feet = NULL; //my_create_sprite("picture/feet.png", sfFalse);
    // }
    // if (gm->state == GAME) {
    //     sfRenderWindow_drawSprite(wind, gm->game, NULL);
    //     move_player(wind, gm);
    //     destroy = 1;
    // }
    if (gm->custom_step == CHOICE) {
        (*list) = make_your_choice(wind, gm, (*list));
        step = 0;
    } else if (gm->custom_step == NAME) {
        if (gm->key.enter == PUSHED) {
            gm->custom_step = GAME;
            gm->key.enter = NOT_PUSHED;
        }
        save_my_choice(wind, (*list), gm);
        /* prompt function*/
    } else if (gm->custom_step == GAME)
        printf("GAME\n");
        /* scene_game */
    // if (gm->state != GAME && destroy == 1) {
    //     sfClock_destroy(gm->clock.anim);
    //     sfSprite_destroy(gm->chara.body);
    // }
}
