/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    disp_player(sfRenderWindow *wind, game_t *gm)
{
    sfIntRect rect = {0, 654, 64, 50};
    sfVector2f pos = {490, 74};

    disp_pl(wind, gm->chara.body, rect, pos);
    disp_pl(wind, gm->chara.hair, rect, pos);
    disp_pl(wind, gm->chara.hat, rect, pos);
    disp_pl(wind, gm->chara.torso, rect, pos);
    disp_pl(wind, gm->chara.shoulder, rect, pos);
    disp_pl(wind, gm->chara.hands, rect, pos);
    disp_pl(wind, gm->chara.legs, rect, pos);
    disp_pl(wind, gm->chara.feet, rect, pos);
}

int    disp_elm(sfRenderWindow *wind, sfSprite *sp,
                sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {3, 3};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
        return (TRUE);
    }
    return (FALSE);
}

void draw_txt(sfRenderWindow *wind, text_t txt)
{
    sfRenderWindow_drawRectangleShape(wind, txt.shape, NULL);
    sfRenderWindow_drawText(wind, txt.name, NULL);
    sfRenderWindow_drawText(wind, txt.hp, NULL);
    sfRenderWindow_drawText(wind, txt.rank, NULL);
    sfRenderWindow_drawText(wind, txt.dmg, NULL);
    sfRenderWindow_drawText(wind, txt.dfs, NULL);
}
