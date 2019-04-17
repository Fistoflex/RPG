/*
** EPITECH PROJECT, 2019
** init_slot
** File description:
** init_slot
*/

#include "my.h"

void    set_link_slot(slot_t **slot, char **tab)
{
    slot_t *tmp = (*slot);
    slot_t *new = malloc(sizeof((*new)));
    sfVector2f pos;

    pos.x = atoi(tab[2]);
    pos.y = atoi(tab[3]);
    new->pos = pos;
    new->sp1 = my_create_sprite(tab[0], sfFalse);
    new->sp2 = my_create_sprite(tab[1], sfFalse);
    new->path = my_strdup(tab[4], KEEP);
    new->next = NULL;
    if ((*slot) == NULL)
        (*slot) = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    the_free(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    init_slot(game_t *gm)
{
    char **slot = read_file("config/save/slot.txt");
    int i = 0;
    char **tab = NULL;

    gm->slot = NULL;
    while (slot[i] != NULL) {
        tab = my_str_to_word_array(slot[i], ';');
        set_link_slot(&gm->slot, tab);
        the_free(tab);
        tab = NULL;
        i++;
    }
    the_free(slot);
}
