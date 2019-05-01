/*
** EPITECH PROJECT, 2019
** annex inventory
** File description:
** annex_inventory
*/

#include "my.h"

void disp_pl(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {7, 7};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
    }
}

sfVector2f position(char *str)
{
    char **tab = my_str_to_word_array(str, ' ');
    sfVector2f pos = {atoi(tab[0]), atoi(tab[1])};

    return (pos);
}