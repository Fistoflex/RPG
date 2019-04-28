/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

void init_inventory(game_t *gm)
{
    sfVector2f pos = {1100, 200};

    gm->chara.bag.inv = my_create_sprite("picture/item/MicrosoftTeams-image.png", sfFalse);
    sfSprite_setPosition(gm->chara.bag.inv, pos);
}