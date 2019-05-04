/*
** EPITECH PROJECT, 2019
** list_enemies
** File description:
** manage list enemies
*/

#include "my.h"

void put_in_enemies(list_emi_t **list, emi_t emi)
{
    list_emi_t *elem = malloc(sizeof(list_emi_t));
    list_emi_t *tmp = *list;

    elem->enemie = emi;
    elem->next = NULL;
    if (tmp == NULL)
        *list = elem;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = elem;
    }
}