/*
** EPITECH PROJECT, 2019
** my_chose
** File description:
** make your choice
*/

#include "my.h"

choice_t *press_left(sfRenderWindow *wind, game_t *gm, choice_t *choice)
{
    sfVector2f principal = {40, 0};
    sfVector2f second = {20, 0};
    sfVector2f pos_m = {-100, 0};
    sfVector2f pos_r = {100, 0};

    choice = choice->prev;
    sfSprite_setScale(choice->iteme_sprite, principal);
    sfSprite_setScale(choice->next->iteme_sprite, second);
    sfSprite_setScale(choice->prev->iteme_sprite, second);
    sfSprite_move(choice->iteme_sprite, pos_m);
    sfSprite_move(choice->prev->iteme_sprite, pos_r);
    sfSprite_move(choice->next->iteme_sprite, pos_m);
    sfRenderWindow_drawSprite(wind, choice->prev->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->next->iteme_sprite, NULL);
    return (choice);
}

choice_t *press_right(sfRenderWindow *wind, game_t *gm, choice_t *choice)
{
    sfVector2f principal = {40, 40};
    sfVector2f second = {20, 20};
    sfVector2f pos_m = {300, 0};
    sfVector2f pos_r = {-600, 0};

    choice = choice->next;
    sfSprite_setScale(choice->iteme_sprite, principal);
    sfSprite_setScale(choice->next->iteme_sprite, second);
    sfSprite_setScale(choice->prev->iteme_sprite, second);
    sfSprite_move(choice->iteme_sprite, pos_m);
    sfSprite_setPosition(choice->prev->iteme_sprite, pos_m);
    sfSprite_move(choice->next->iteme_sprite, pos_r);
    sfRenderWindow_drawSprite(wind, choice->prev->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->iteme_sprite, NULL);
    sfRenderWindow_drawSprite(wind, choice->next->iteme_sprite, NULL);
    return (choice);
}

list_t *press_up(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    list->iteme->state_iteme = FALSE;
    list = list->prev;
    return (list);
}

list_t *press_down(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    list->iteme->state_iteme = TRUE;
    list = list->next;
    return (list);
}