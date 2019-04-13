/*
** EPITECH PROJECT, 2019
** right
** File description:
** right
*/

#include "my.h"

void	to_the_right(sfRenderWindow *wind, game_t *gm, sfIntRect *rect)
{
    static int left = 0;
    int top = 717;
    int width = 64;
    int height = 50;

    gm->chara.pos.x += 5;
    (*rect) = my_create_rect(height, width, top, left);
    if (my_clock(gm->clock.anim) > 0.01) {
        left += 64;
        if ((*rect).left >= 504)
            left = 0;
        sfClock_restart(gm->clock.anim);
    }
    set_rect_stuff(wind, gm, (*rect));
}
