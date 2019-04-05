/*
** EPITECH PROJECT, 2019
** save my choice
** File description:
** save_my_choice
*/

#include "my.h"

void save_my_choice(sfRenderWindow *wind, list_t *list, game_t *gm)
{
    while (list->state_link != TRUE)
        list = list->next;
    list = list->next;
    gm->chara.hair = list->iteme->iteme_sprite;
    list = list->next;
    gm->chara.body = list->iteme->iteme_sprite;
    list = list->next;
    gm->chara.torso = list->iteme->iteme_sprite;
    list = list->next;
    gm->chara.legs = list->iteme->iteme_sprite;
    list = list->next;
    gm->chara.feet = list->iteme->iteme_sprite;
    sfRenderWindow_drawSprite(wind, gm->chara.body, NULL);
    sfRenderWindow_drawSprite(wind, gm->chara.hair, NULL);
    sfRenderWindow_drawSprite(wind, gm->chara.torso, NULL);
    sfRenderWindow_drawSprite(wind, gm->chara.feet, NULL);
    sfRenderWindow_drawSprite(wind, gm->chara.legs, NULL);
    /* FREE LA LISTE*/
}