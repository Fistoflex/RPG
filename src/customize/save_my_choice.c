/*
** EPITECH PROJECT, 2019
** save my choice
** File description:
** save_my_choice
*/

#include "my.h"

void free_my_iteme(choice_t *iteme)
{
    while (iteme->state_link != TRUE) {
        sfSprite_destroy(iteme->iteme_sprite);
        free(iteme->str);
        iteme = iteme->next;
        free(iteme->prev);
    }
}

void free_my_list(list_t *list)
{
    while (list->state_link != TRUE) {
        free_my_iteme(list->iteme);
        list = list->next;
        free(list->prev);
    }
}

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
    gm->chara.hat = NULL;
    gm->chara.shoulder = NULL;
    gm->chara.hands = NULL;
    sfRenderWindow_drawSprite(wind, gm->chara.feet, NULL);
    sfRenderWindow_drawSprite(wind, gm->chara.legs, NULL);
    free_my_list(list);
}
