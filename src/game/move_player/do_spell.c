/*
** EPITECH PROJECT, 2019
** do all spell
** File description:
** do_spell
*/

#include "my.h"

int give_top_dash(game_t *gm, int top_a, int top)
{
    if (top_a == 717) {
        top += 192;
        if (gm->colli.est == FALSE)
            gm->chara.pos.x += 20;
    }
    if (top_a == 654) {
        top += 128;
        if (gm->colli.south == FALSE)
            gm->chara.pos.y += 20;
    }
    if (top_a == 589) {
        top += 64;
        if (gm->colli.west == FALSE)
            gm->chara.pos.x -= 20;
    } else if (top == 1034)
        if (gm->colli.north == FALSE)
            gm->chara.pos.y -= 20;
    return (top);
}

int good_top_wp(int top_a, game_t *gm)
{
    int top = 0;
    float rt = 0;

    if (top_a == 717) {
        top += 200;
        rt += 90;
        sfRectangleShape_setPosition(gm->hitbox.wp.s,
        set_2f(gm->chara.pos.x + 90, gm->chara.pos.y));
    }
    if (top_a == 654) {
        top += 400;
        rt += 180;
        sfRectangleShape_setPosition(gm->hitbox.wp.s,
        set_2f(gm->chara.pos.x + 70, gm->chara.pos.y + 70));
    }
    if (top_a == 589) {
        top += 600;
        rt -= 90;
        sfRectangleShape_setPosition(gm->hitbox.wp.s,
        set_2f(gm->chara.pos.x - 20, gm->chara.pos.y + 80));
    }
    sfRectangleShape_setRotation(gm->hitbox.wp.s, rt);
    return (top);
}

void rect_wp(sfRenderWindow *wind, game_t *gm, int top_a)
{
    sfVector2f pos_s = {gm->chara.pos.x - 10, gm->chara.pos.y - 15};
    static int left_s = 0;
    int top_s = good_top_wp(top_a, gm);
    int width_s = 200;
    int height_s = 200;
    sfIntRect wp;

    sfRenderWindow_drawShape(wind, gm->hitbox.wp.s, NULL);
    wp = my_create_rect(height_s, width_s, top_s, left_s);
    if (my_clock(gm->clock.enter) > 0.1) {
        left_s += 200;
        if (wp.left >= 200) {
            left_s = 0;
            gm->key.s_s = NOT_PUSHED;
        }
        sfClock_restart(gm->clock.enter);
    }
    if (gm->chara.wp != NULL)
        disp_my_wp(gm->chara.wp, pos_s, wp, wind);
}

void do_slash(sfRenderWindow *wind, game_t *gm, sfIntRect *rect, int top_a)
{
    static int left = 0;
    int top = top_a + 255;
    int width = 64;
    int height = 50;

    (*rect) = my_create_rect(height, width, top, left);
    rect_wp(wind, gm, top_a);
    if (my_clock(gm->clock.anim) > 0.05) {
        left += 64;
        if ((*rect).left >= 280)
            left = 0;
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

    top = give_top_dash(gm, top_a, top);
    (*rect) = my_create_rect(height, width, top, left);
    set_rect_stuff(wind, gm, (*rect));
}