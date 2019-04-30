/*
** EPITECH PROJECT, 2019
** draw_hp
** File description:
** draw_hp
*/

#include "my.h"

heal_t *init_normal_hp(int n)
{
    int i = 0;
    heal_t *hp = NULL;
    sfVector2f pos = {100, 100};

    while (n != i) {
        init_my_link_hp(&hp, pos);
        pos.x += 50;
        i++;
    }
}

void draw_hp(sfRenderWindow *win, heal_t *hp)
{
    heal_t *tmp = hp;
    sfSprite *empty = my_create_sprite("picture/item/empty_heart.png", sfFalse);
    sfSprite *full = my_create_sprite("picture/item/heart.png", sfFalse);

    while (tmp != NULL) {
        if (tmp->state == FALSE) {
            sfSprite_setPosition(empty, tmp->pos);
            sfRenderWindow_drawSprite(win, empty, NULL);
        } else if (tmp->state == TRUE) {
            sfSprite_setPosition(full, tmp->pos);
            sfRenderWindow_drawSprite(win, full, NULL);
        }
        tmp = tmp->next;
    }
}
