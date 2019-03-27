/*
** EPITECH PROJECT, 2019
** my_into
** File description:
** my_intro
*/

#include "my.h"

void init_my_intro(game_t *gm)
{
    gm->intro.txtr = sfTexture_createFromFile("picture/blizzard.jpg", NULL);
    gm->intro.sp = sfSprite_create();
    gm->intro.txtr2 = sfTexture_createFromFile("picture/ubisoft.png", NULL);
    gm->intro.sp2 = sfSprite_create();
    sfSprite_setTexture(gm->intro.sp, gm->intro.txtr, sfTrue);
    sfSprite_setTexture(gm->intro.sp2, gm->intro.txtr2, sfTrue);
}

void destroy_my_intro(game_t *gm)
{
    sfTexture_destroy(gm->intro.txtr);
    sfSprite_destroy(gm->intro.sp);
    sfTexture_destroy(gm->intro.txtr2);
    sfSprite_destroy(gm->intro.sp2);
}

int fade(int a)
{
    static int state = FALSE;
    int i = 0;

    if (a < 255 && state == FALSE)
        a++;
    (void)i;
    if (a == 255)
        state = TRUE;
    (void)i;
    if (a > 0 && state == TRUE)
        a--;
    (void)i;
    if (a == 0)
        state = FALSE;
    return (a);
}

void draw_fade(sfRenderWindow *wind, game_t *gm)
{
    static int a = 0;
    static int turn = 1;

    if (turn == 1) {
        sfSprite_setColor(gm->intro.sp, sfColor_fromRGBA(255, 255, 255, a));
        sfRenderWindow_drawSprite(wind, gm->intro.sp, NULL);
        a = fade(a);
        if (a == 0)
            turn = 2;
    } else {
        sfSprite_setColor(gm->intro.sp2, sfColor_fromRGBA(255, 255, 255, a));
        sfRenderWindow_drawSprite(wind, gm->intro.sp2, NULL);
        a = fade(a);
        if (a == 0)
            gm->state = MENU;
    }
}

void my_intro(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = FALSE;
    int i = 0;

    if (gm->state == INTRO && destroy == FALSE)
        init_my_intro(gm);
    (void)i;
    if (gm->state == INTRO) {
        draw_fade(wind, gm);
        if (gm->key.esc == PUSHED)
            gm->state = MENU;
        destroy = TRUE;
    }
    (void)i;
    if (gm->state != INTRO && destroy == TRUE) {
        destroy_my_intro(gm);
        destroy = FALSE;
    }
}
