/*
** EPITECH PROJECT, 2019
** create_link_list
** File description:
** create different link liste
*/

#include "my.h"

void malloc_my_link_list(choice_t **env, sfSprite *iteme, char *str)
{
    choice_t *tmp = (*env);
    choice_t *new = NULL;
    choice_t *first = (*env);

    new = malloc(sizeof(*new));
    new->iteme_sprite = iteme;
    new->str = str;
    new->state_iteme = FALSE;
    new->state_link = TRUE;
    new->next = (*env);
    new->prev = NULL;
    if (tmp == NULL)
        (*env) = new;
    else {
        while (tmp->state_link != TRUE)
            tmp = tmp->next;
        tmp->state_link = FALSE;
        tmp->next = new;
        new->prev = tmp;
        first->prev = new;
    }
}