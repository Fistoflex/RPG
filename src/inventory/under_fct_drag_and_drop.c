/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

void    loop_one(game_t *gm, bag_t **bag, int *state)
{
    int i = 0;
    sfFloatRect rec;

    while (i != 15 && gm->clik != PUSHED && (*state) != 1) {
        rec = sfRectangleShape_getGlobalBounds((*bag)->shape);
        if (gm->tmp->state == (*bag)->state && sfFloatRect_contains(&rec,
            gm->mouse.release.x, gm->mouse.release.y)) {
            gm->tmp = swap_elem(bag, gm->tmp, gm);
            gm->clik = NOT_PUSHED;
            gm->mouse.release.x = -10;
            gm->mouse.release.y = -10;
            (*state) = 1;
        }
        (*bag) = (*bag)->next;
        i++;
    }
}
