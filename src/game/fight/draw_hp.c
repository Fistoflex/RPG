/*
** EPITECH PROJECT, 2019
** draw_hp
** File description:
** draw_hp
*/

#include "my.h"

heal_t *init_normal_hp(int n, game_t *gm)
{
    int i = 0;
    heal_t *hp = NULL;
    sfVector2f pos = gm->chara.pos;

    while (n != i) {
        init_my_link_hp(&hp, pos);
        pos.x += 50;
        i++;
    }
    return (hp);
}

void draw_hp(sfRenderWindow *win, heal_t *hp, game_t *gm)
{
    sfVector2f pos = set_2f(gm->chara.pos.x - 550, gm->chara.pos.y - 300);
    heal_t *tmp = hp;
    sfSprite *empty = my_create_sprite("picture/item/empty_heart.png", sfFalse);
    sfSprite *full = my_create_sprite("picture/item/heart.png", sfFalse);

    while (tmp != NULL) {
        if (tmp->state == FALSE) {
            sfSprite_setPosition(empty, pos);
            sfRenderWindow_drawSprite(win, empty, NULL);
        } else if (tmp->state == TRUE) {
            sfSprite_setPosition(full, pos);
            sfRenderWindow_drawSprite(win, full, NULL);
        }
        pos.x += 50;
        tmp = tmp->next;
    }
}
