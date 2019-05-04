/*
** EPITECH PROJECT, 2019
** init_slot
** File description:
** init_slot
*/

#include "my.h"

int slot_activate(char *tmp)
{
    char *path = my_strcat(tmp, "stat_slot.txt", KEEP, KEEP);
    char **tab = read_file(path);

    if (my_strcmp(tab[0], "activate") != 0)
        return (1);
    return (0);
}

sfVector2f the_pos(char *str)
{
    char **tab = my_str_to_word_array(str, ' ');
    sfVector2f pos = {my_getnbr(tab[0]), my_getnbr(tab[1])};

    return (pos);
}

slot_t    set_link_slot(slot_t slot, char **tab)
{
    sfVector2f pos_s = the_pos(tab[1]);
    sfVector2f pos_p = the_pos(tab[3]);
    sfVector2f pos_n = the_pos(tab[4]);

    slot.pos_s = pos_s;
    slot.pos_p = pos_p;
    slot.pos_n = pos_n;
    slot.slot = my_create_sprite(tab[0], sfFalse);
    slot.path = my_strdup(tab[2], KEEP);
    if (slot_activate(slot.path) == 1) {
        slot.stat = 1;
    }
    else {
        slot.stat = 0;
        slot.chara = set_chara_elem(slot.path);
    }
    return (slot);
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

slot_t    set_one_slot(slot_t one, int i)
{
    char **slot = read_file("config/save/slot.txt");
    char **tab = NULL;

    tab = my_str_to_word_array(slot[i], ';');
    one = set_link_slot(one, tab);
    the_free(tab);
    return (one);
}
