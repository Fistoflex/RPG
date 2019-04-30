/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

char **all_path(void)
{
    char **tab = malloc(sizeof(char *) * 5);

    tab[0] = "config/save/hair.txt";
    tab[1] = "config/save/torso.txt";
    tab[2] = "config/save/legs.txt";
    tab[3] = "config/save/feet.txt";
    tab[4] = NULL;
    return (tab);
}

void init_inventory(game_t *gm)
{
    sfVector2f pos = {410, 0};
    sfVector2f size = {3, 3};
    static int i = 0;

    if (i == 0) {
        init_inv_elem(gm);
        i++;
    }
    gm->chara.bag.inv = my_create_sprite("picture/item/MicrosoftTeams-image.png"
    , sfFalse);
    sfSprite_setPosition(gm->chara.bag.inv, pos);
    sfSprite_scale(gm->chara.bag.inv, size);
}