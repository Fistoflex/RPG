/*
** EPITECH PROJECT, 2019
** cod
** File description:
** cond
*/

#include "my.h"

void    my_stuff(sfSprite *sp, sfVector2f pos, sfIntRect rect, sfRenderWindow *wind)
{
    sfSprite_setPosition(sp, pos);
    sfSprite_setTextureRect(sp, rect);
    sfRenderWindow_drawSprite(wind, sp, NULL);
}

void    set_rect_stuff(sfRenderWindow *wind, game_t *gm, sfIntRect rect)
{
    if (gm->chara.body != NULL)
        my_stuff(gm->chara.body, gm->chara.pos, rect, wind);
    if (gm->chara.hair != NULL)
        my_stuff(gm->chara.hair, gm->chara.pos, rect, wind);
    if (gm->chara.hat != NULL)
	my_stuff(gm->chara.hat, gm->chara.pos, rect, wind);
    if (gm->chara.torso != NULL)
        my_stuff(gm->chara.torso, gm->chara.pos, rect, wind);
    if (gm->chara.shoulder != NULL)
	my_stuff(gm->chara.shoulder, gm->chara.pos, rect, wind);
    if (gm->chara.hands != NULL)
        my_stuff(gm->chara.hands, gm->chara.pos, rect, wind);
    if (gm->chara.legs != NULL)
        my_stuff(gm->chara.legs, gm->chara.pos, rect, wind);
    if (gm->chara.feet != NULL)
        my_stuff(gm->chara.feet, gm->chara.pos, rect, wind);
}

void	move_player(sfRenderWindow *wind, game_t *gm)
{
    static sfIntRect rect;

    if (gm->key.left == PUSHED) {
        to_the_left(wind, gm, &rect);
        gm->key.left = NOT_PUSHED;
    }
    if (gm->key.right == PUSHED) {
        to_the_right(wind, gm, &rect);
        gm->key.right = NOT_PUSHED;
    }
    if (gm->key.up == PUSHED) {
        to_the_top(wind, gm, &rect);
        gm->key.up = NOT_PUSHED;
    }
    if (gm->key.down == PUSHED) {
        to_the_bot(wind, gm, &rect);
        gm->key.down = NOT_PUSHED;
    }
    set_rect_stuff(wind, gm, rect);
}
