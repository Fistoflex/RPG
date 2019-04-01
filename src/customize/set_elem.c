/*
** EPITECH PROJECT, 2019
** set_hair
** File description:
** set_hair
*/

#include "my.h"

void    my_free(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    set_list(choice_t **elem, char **tab)
{
    int i = 0;
    char **tmp = NULL;

    while (tab[i] != NULL) {
        tmp = my_str_to_word_array(tab[i], ';');
        malloc_my_link_choice(elem, my_create_sprite(tmp[0], sfFalse), tmp[1]);
        my_free(tmp);
        i++;
    }
}
