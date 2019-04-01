/*
** EPITECH PROJECT, 2019
** customer_scene
** File description:
** custome you champion
*/

#include "my.h"

list_t *make_your_choice(sfRenderWindow *wind, game_t *gm, list_t *list)
{
    static sfIntRect rect;

    //printf("%s\n", list->iteme->str);
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
    //printf("---%s\n", list->iteme->str);
    sfRenderWindow_drawSprite(wind, list->iteme->iteme_sprite, NULL);
    //printf("[%s]\n", list->iteme->str);
    //     list->iteme = press_left(wind, gm, list->iteme);
    //     gm->key.left = NOT_PUSHED;
    // }
    // if (gm->key.right == PUSHED) {
    //     list->iteme = press_right(wind, gm, list->iteme);
    //     gm->key.right = NOT_PUSHED;
    // }
    // if (gm->key.up == PUSHED) {
    //     list = list->prev;
    //     //list = press_up(wind, gm, list);
    //     gm->key.up = NOT_PUSHED;
    // }
    // if (gm->key.down == PUSHED) {
    //     list = list->next;
    //     printf("->[%s]\n", list->iteme->str);
    //     // list = press_down(wind, gm, list);
    //     gm->key.down = NOT_PUSHED;
    // }
    return (list);
}
//la liste recommence depuis le debut a chaque fois!!!

//fonction qui affiche en petit, grand, change les coord en fonction
list_t *init_my_custome(void)
{
    int n = 0;
    list_t *list = NULL;
    choice_t *hair = NULL;
    choice_t *top = NULL;

    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/black.png", sfFalse), "black");
    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/blue2.png", sfFalse), "blue");
    malloc_my_link_choice(&hair, my_create_sprite("picture/Character_assets/MALE/Male - Hair/blonde2.png", sfFalse), "blond");
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/magenta.png", sfFalse), "magenta_p");
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/teal.png", sfFalse), "teal_p");
    malloc_my_link_choice(&top, my_create_sprite("picture/Character_assets/MALE/Male - Pants/red.png", sfFalse), "red_p");
    malloc_my_link_list(&list, hair);
    // while (list->iteme->state_link != TRUE) {
    //     printf("%s\n", list->iteme->str);
    //     list->iteme = list->iteme->next;
    // }
    // printf("%s\n", list->iteme->str);
    malloc_my_link_list(&list, top);
    // list = list->next;
    // while (list->iteme->state_link != TRUE) {
    //     printf("%s\n", list->iteme->str);
    //     list->iteme = list->iteme->next;
    // }
    // printf("%s\n", list->iteme->str);
    return (list);
}
//top choice , mid, bot
//valider -> parcoure toute les listes, et check state_iteme*
