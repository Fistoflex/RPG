/*
** EPITECH PROJECT, 2019
** customer_scene
** File description:
** custome you champion
*/

#include "my.h"

void draw_my_p_choice(sfRenderWindow *wind, choice_t *choice)
{
    sfVector2f pos_p = {660, 340};
    sfVector2f size_p = {10, 10};
    sfIntRect rect;

    rect.height = 49;
    rect.left = 0;
    rect.width = 64;
    rect.top = 650;
    sfSprite_setTextureRect(choice->iteme_sprite, rect);
    sfSprite_setPosition(choice->iteme_sprite, pos_p);
    sfSprite_setScale(choice->iteme_sprite, size_p);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
}

void draw_my_perso(sfRenderWindow *wind, choice_t *choice)
{
    sfVector2f pos_p = {660, 340};
    sfVector2f size_p = {10, 10};
    sfIntRect rect;

    rect.height = 49;
    rect.left = 0;
    rect.width = 64;
    rect.top = 650;
    sfSprite_setTextureRect(choice->iteme_sprite, rect);
    sfSprite_setPosition(choice->iteme_sprite, pos_p);
    sfSprite_setScale(choice->iteme_sprite, size_p);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
}

void draw_my_s_choice(sfRenderWindow *wind, choice_t *choice)
{
    sfVector2f pos_s = {500, 440};
    sfVector2f pos_p = {1020, 440};
    sfVector2f size_s = {7, 7};
    sfIntRect rect;

    rect.height = 49;
    rect.left = 0;
    rect.width = 64;
    rect.top = 650;
    sfSprite_setTextureRect(choice->next->iteme_sprite, rect);
    sfSprite_setPosition(choice->next->iteme_sprite, pos_p);
    sfSprite_setScale(choice->next->iteme_sprite, size_s);
    sfRenderWindow_drawSprite(wind, choice->next->iteme_sprite, NULL);
    sfSprite_setTextureRect(choice->prev->iteme_sprite, rect);
    sfSprite_setPosition(choice->prev->iteme_sprite, pos_s);
    sfSprite_setScale(choice->prev->iteme_sprite, size_s);
    sfRenderWindow_drawSprite(wind, choice->prev->iteme_sprite, NULL);
}

void draw_all_choice(sfRenderWindow *wind, list_t *list)
{
    draw_my_p_choice(wind, list->iteme);
    draw_my_s_choice(wind, list->iteme);
    while (list->state_link != TRUE) {
        draw_my_p_choice(wind, list->next->iteme);
        list = list->next;
    }
    draw_my_p_choice(wind, list->next->iteme);
}

list_t *make_your_choice(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    draw_all_choice(wind, list);
    if (gm->key.left == PUSHED) {
        list->iteme = list->iteme->next;
        gm->key.left = NOT_PUSHED;
    }
    if (gm->key.right == PUSHED) {
        list->iteme = list->iteme->prev;
        gm->key.right = NOT_PUSHED;
    }
    if (gm->key.up == PUSHED) {
        list = list->prev;
        gm->key.up = NOT_PUSHED;
    }
    if (gm->key.down == PUSHED) {
        list = list->next;
        gm->key.down = NOT_PUSHED;
    }
    return (list);
}
