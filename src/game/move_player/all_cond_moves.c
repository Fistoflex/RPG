/*
** EPITECH PROJECT, 2019
** cod
** File description:
** cond
*/

#include "my.h"

void my_stuff(sfSprite *sp, sfVector2f pos, sfIntRect rect, sfRenderWindow *win)
{
    sfVector2f scale = {1, 1};

    sfSprite_setScale(sp, scale);
    sfSprite_setPosition(sp, pos);
    sfSprite_setTextureRect(sp, rect);
    sfRenderWindow_drawSprite(win, sp, NULL);
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

void spell_player(sfRenderWindow *wind, game_t *gm, sfIntRect rect, int old)
{
    if (gm->key.s_s == PUSHED)
        do_slash(wind, gm, &rect, old);
    if (gm->key.s_d == PUSHED)
            do_dash(wind, gm, &rect, old);
    if (gm->key.down == PUSHED || gm->key.up == PUSHED ||
        gm->key.right == PUSHED || gm->key.left == PUSHED ||
        gm->key.s_d == PUSHED)
        gm->key.s_s = NOT_PUSHED;
    if (gm->key.down == PUSHED || gm->key.up == PUSHED ||
        gm->key.right == PUSHED || gm->key.left == PUSHED)
        gm->key.s_d = NOT_PUSHED;
    if (my_clock(gm->clock.anim) > 0.3) {
        gm->key.s_d = NOT_PUSHED;
        sfClock_restart(gm->clock.anim);
    }
}

void move_player(sfRenderWindow *wind, game_t *gm)
{
    static int old = 654;
    static sfIntRect rect;

    if (gm->key.left == PUSHED)
        old = to_the_left(wind, gm, &rect);
    if (gm->key.right == PUSHED)
        old = to_the_right(wind, gm, &rect);
    if (gm->key.up == PUSHED)
        old = to_the_top(wind, gm, &rect);
    if (gm->key.down == PUSHED)
        old = to_the_bot(wind, gm, &rect);
    if (gm->key.down == NOT_PUSHED && gm->key.up == NOT_PUSHED &&
        gm->key.right == NOT_PUSHED && gm->key.left == NOT_PUSHED &&
        gm->key.s_s == NOT_PUSHED && gm->key.s_d == NOT_PUSHED)
        set_rect_stuff(wind, gm, rect);
    spell_player(wind, gm, rect, old);
    gm->key.down = NOT_PUSHED;
    gm->key.up = NOT_PUSHED;
    gm->key.right = NOT_PUSHED;
    gm->key.left = NOT_PUSHED;
}
