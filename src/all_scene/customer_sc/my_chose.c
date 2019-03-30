/*
** EPITECH PROJECT, 2019
** my_chose
** File description:
** make your choice
*/

#include "my.h"

void press_left(sfRenderWindow *wind, game_t *gm, choice_t *choice)
{
    sfVector2f principal = {40, 40};
    sfVector2f second = {20, 20};
    sfVector2f pos_m = {1000, 800};
    sfVector2f pos_l = {700, 800};
    sfVector2f pos_r = {1300, 800};

    choice = choice->prev;
    sfSprite_setScale(choice->iteme_sprite, principal);
    sfSprite_setScale(choice->next->iteme_sprite, second);
    sfSprite_setScale(choice->prev->iteme_sprite, second);
    sfSprite_setPosition(choice->iteme_sprite, pos_m);
    sfSprite_setPosition(choice->prev->iteme_sprite, pos_l);
    sfSprite_setPosition(choice->next->iteme_sprite, pos_r);
    sfRenderWindow_drawSprite(wind, choice->prev->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->next->iteme_sprite, NULL);
}

void press_right(sfRenderWindow *wind, game_t *gm, choice_t *choice)
{
    sfVector2f principal = {40, 40};
    sfVector2f second = {20, 20};
    sfVector2f pos_m = {1000, 800};
    sfVector2f pos_l = {700, 800};
    sfVector2f pos_r = {1300, 800};

    choice = choice->next;
    sfSprite_setScale(choice->iteme_sprite, principal);
    sfSprite_setScale(choice->next->iteme_sprite, second);
    sfSprite_setScale(choice->prev->iteme_sprite, second);
    sfSprite_setPosition(choice->iteme_sprite, pos_m);
    sfSprite_setPosition(choice->prev->iteme_sprite, pos_r);
    sfSprite_setPosition(choice->next->iteme_sprite, pos_l);
    sfRenderWindow_drawSprite(wind, choice->prev->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->next->iteme_sprite, NULL);
}

void press_up(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    list->iteme->state_iteme = FALSE;
    list = list->prev;
}

void press_left(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    list->iteme->state_iteme = TRUE;
    list = list->next;
}