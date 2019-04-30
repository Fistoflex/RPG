/*
** EPITECH PROJECT, 2019
** do all spell
** File description:
** do_spell
*/

#include "my.h"

void do_slash(sfRenderWindow *wind, game_t *gm, sfIntRect *rect, int top_a)
{
    static int left = 0;
    int top = top_a + 255;
    int width = 64;
    int height = 50;

    (*rect) = my_create_rect(height, width, top, left);
    if (my_clock(gm->clock.anim) > 0.1) {
        left += 64;
        if ((*rect).left >= 280) {
            left = 0;
            gm->key.s_s = NOT_PUSHED;
        }
        sfClock_restart(gm->clock.anim);
    }
    set_rect_stuff(wind, gm, (*rect));
}

void do_dash(sfRenderWindow *wind, game_t *gm, sfIntRect *rect, int top_a)
{
    int left = 197;
    int top = 1034;
    int width = 64;
    int height = 50;

    if (top_a == 717) {
        top += 192;
        gm->chara.pos.x += 20;
    }
    if (top_a == 654) {
        top += 128;
        gm->chara.pos.y += 20;
    }
    if (top_a == 589) {
        top += 64;
        gm->chara.pos.x -= 20;
    } else if (top == 1034)
        gm->chara.pos.y -= 20;
    (*rect) = my_create_rect(height, width, top, left);
    set_rect_stuff(wind, gm, (*rect));
}