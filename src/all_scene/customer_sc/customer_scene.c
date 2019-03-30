/*
** EPITECH PROJECT, 2019
** customer_scene
** File description:
** custome you champion
*/

#include "my.h"

void make_your_choice(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    static sfIntRect rect;

    printf("[%s]\n", list->iteme->str);
    if (gm->key.left == PUSHED) {
        press_left(wind, gm, list->iteme);
        gm->key.left = NOT_PUSHED;
    }
    if (gm->key.right == PUSHED) {
        press_right(wind, gm, list->iteme);
        gm->key.right = NOT_PUSHED;
    }
    if (gm->key.up == PUSHED) {
        press_up(wind, gm, list);
        gm->key.up = NOT_PUSHED;
    }
    if (gm->key.down == PUSHED) {
        press_down(wind, gm, list);
        gm->key.down = NOT_PUSHED;
    }
}

//fonction qui affiche en petit, grand, change les coord en fonction
list_t *init_my_custome(void)
{
    int n = 0;
    list_t *list = NULL;
    choice_t *hair = NULL;
    choice_t *top = NULL;

    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/black.png", sfFalse), strdup("black"));
    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/blue2.png", sfFalse), strdup("blue"));
    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/blonde2.png", sfFalse), strdup("blond"));
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/magenta.png", sfFalse), strdup("blond"));
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/teal.png", sfFalse), strdup("blond"));
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/red.png", sfFalse), strdup("blond"));
    malloc_my_link_list(&list, hair);
    printf("%s\n", list->iteme->str);
    malloc_my_link_list(&list, top);
    printf("%s\n", list->next->iteme->str);
    return (list);
}
//top choice , mid, bot
//valider -> parcoure toute les listes, et check state_iteme*
