/*
** EPITECH PROJECT, 2019
** bot
** File description:
** bot
*/

#include "my.h"

void    to_the_bot(sfRenderWindow *wind, game_t *gm, sfIntRect *rect)
{
    static int left = 0;
    int top = 654;
    int width = 64;
    int height = 49;

    gm->chara.pos.y += 5;
    (*rect) = my_create_rect(height, width, top, left);
    if (my_clock(gm->clock.anim) > 0.01) {
	left += 64;
	if ((*rect).left >= 512)
            left = 0;
	sfClock_restart(gm->clock.anim);
    }
    set_rect_stuff(wind, gm, (*rect));
}
