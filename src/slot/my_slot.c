/*
** EPITECH PROJECT, 2019
** slot
** File description:
** slot
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

void    display_slots(sfRenderWindow *wind, game_t *gm)
{
    slot_t *slot = gm->slot;

    while (slot != NULL) {
        if (my_over_slot(slot->sp1, slot->sp2, gm) == 1) {
            sfSprite_setPosition(slot->sp2, slot->pos);
            sfRenderWindow_drawSprite(wind, slot->sp2, NULL);
        } else {
            sfSprite_setPosition(slot->sp1, slot->pos);
            sfRenderWindow_drawSprite(wind, slot->sp1, NULL);
        }
        slot = slot->next;
    }
}

void    my_slot(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == SLOT && destroy == 0)
        init_slot(gm);
    if (gm->state == SLOT) {
        display_slots(wind, gm);
        destroy = 1;
    }
    if (gm->state != SLOT && destroy == 1) {
        destroy = 0;
    }
}
