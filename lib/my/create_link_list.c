/*
** EPITECH PROJECT, 2019
** create_link_list
** File description:
** create different link liste
*/

#include "../../include/my.h"

void malloc_my_link_choice(choice_t **env, sfSprite *iteme,
                            char *str, char *path)
{
    choice_t *tmp = (*env);
    choice_t *new = malloc(sizeof(*new));
    choice_t *first = (*env);

    new->iteme_sprite = iteme == NULL ? NULL: iteme;
    new->str = str == NULL ? NULL: str;
    new->state_iteme = FALSE;
    new->path = my_strdup(path, KEEP);
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

void malloc_my_link_list(list_t **env, choice_t *choice)
{
    list_t *tmp = (*env);
    list_t *new = NULL;
    list_t *first = (*env);

    new = malloc(sizeof((*new)));
    new->iteme = choice;
    new->next = (*env);
    new->prev = NULL;
    new->state_link = TRUE;
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
