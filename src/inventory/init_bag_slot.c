/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

sfVector2f right_pos(int state, int i, char *path)
{
    char **tab = read_file(path);
    char **tmp = NULL;

    tmp = my_str_to_word_array(tab[i], ' ');
    sfVector2f pos = set_coord(tmp[state]);

    return (pos);
}

itm_t init_struct(char *str, bag_t **bag, int i, char *path)
{
    char **tab = my_str_to_word_array(str, ' ');
    char **tmp = my_str_to_word_array(tab[2], ',');
    itm_t item;
    sfColor color = set_color(tmp);

    item.path = my_strdup(tab[1], KEEP);
    (*bag)->state = atoi(tab[0]);
    item.pos = right_pos(atoi(tab[3]), i, path);
    item.tab = my_str_to_word_array(tab[2], ',');
    item.txt = init_text(tmp);
    sfRectangleShape_setFillColor((*bag)->shape, color);
    item.sp = my_create_sprite(tab[1], sfFalse);
    return (item);
}

itm_t set_default(bag_t **bag)
{
    itm_t item;

    item.path = NULL;
    item.sp = NULL;
    item.tab = NULL;
    (*bag)->state = NONE;
    return (item);
}

void set_item(bag_t **bag, char **tab, char *path)
{
    int i = 0;
    itm_t item;

    while (tab[i] != NULL) {
        if (my_strcmp(tab[i], "none") == 0)
            item = set_default(bag);
        else
            item = init_struct(tab[i], bag, i, path);
        (*bag)->itm = item;
        (*bag) = (*bag)->next;
        i++;
    }
}

void init_bag(game_t *gm)
{
    int i = 0;
    char *pth = my_strcat(gm->chara.path.slot, "bag", KEEP, KEEP);
    char **tab = read_file(pth);
    bag_t *bag = gm->chara.bag.bag;
    char *path = my_strdup("config/save/right_pos", KEEP);

    while (i != 14) {
        bag = bag->next;
        i++;
    }
    set_item(&bag, tab, path);
}