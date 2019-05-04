/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

int my_over_slot(sfSprite *sp1, sfSprite *sp2, game_t *gm)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sp1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sp2);

    if (sfFloatRect_contains(&rect1, gm->mouse.moved.x, gm->mouse.moved.y))
        return (1);
    else if (sfFloatRect_contains(&rect2, gm->mouse.moved.x, gm->mouse.moved.y))
        return (1);
    return (0);
}

void    disp(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {4, 4};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
    }
}

void    display_slots(sfRenderWindow *wind, slot_t slot)
{
    sfIntRect rect = {0, 654, 64, 50};

    sfSprite_setPosition(slot.slot, slot.pos_s);
    if (slot.stat == 1)
        sfRenderWindow_drawSprite(wind, slot.slot, NULL);
    else {
        disp(wind, slot.chara.body, rect, slot.pos_p);
        disp(wind, slot.chara.hair, rect, slot.pos_p);
        disp(wind, slot.chara.hat, rect, slot.pos_p);
        disp(wind, slot.chara.torso, rect, slot.pos_p);
        disp(wind, slot.chara.shoulder, rect, slot.pos_p);
        disp(wind, slot.chara.hands, rect, slot.pos_p);
        disp(wind, slot.chara.legs, rect, slot.pos_p);
        disp(wind, slot.chara.feet, rect, slot.pos_p);
        sfText_setPosition(slot.chara.nm, slot.pos_n);
        sfRenderWindow_drawText(wind, slot.chara.nm, NULL);
    }
}

int slot_is_select(sfSprite *sp1, game_t *gm)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sp1);

    if (sfFloatRect_contains(&rect1, gm->mouse.button.x, gm->mouse.button.y))
        return (1);
    return (0);
}

char    *slot_select(slot_t one, int *select, char *path, game_t *gm)
{
    slot_t slot = one;

    if (path != NULL)
        return (path);
    if (slot_is_select(slot.slot, gm) == 1) {
        (*select) = 1;
        return (slot.path);
    }
    return (NULL);
}
