/*
** EPITECH PROJECT, 2019
** top
** File description:
** top
*/

#include "my.h"

void    to_the_top(sfRenderWindow *wind, game_t *gm, sfIntRect *rect)
{
    static int left = 0;
    int top = 527;
    int width = 64;
    int height = 48;

    gm->chara.pos.y -= 5;
    (*rect) = my_create_rect(height, width, top, left);
    if (my_clock(gm->clock.anim) > 0.05) {
        left += 64;
        if ((*rect).left >= 512)
            left = 0;
        sfClock_restart(gm->clock.anim);
    }
    set_rect_stuff(wind, gm, (*rect));
}
