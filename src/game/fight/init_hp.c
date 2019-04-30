/*
** EPITECH PROJECT, 2019
** init hp
** File description:
** init the link list of hp
*/

#include "my.h"

void init_my_link_hp(heal_t **hp, sfVector2f pos)
{
    heal_t *tmp = (*hp);
    heal_t *new = NULL;
    sfVector2f old = {-1, -1};

    new = malloc(sizeof(*new));
    new->old_pos = old;
    new->pos = pos;
    new->state = TRUE;
    new->next = NULL;
    if (tmp == NULL)
        (*hp) = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        new->old_pos = tmp->pos;
        tmp->next = new;
    }
}