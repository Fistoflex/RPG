/*
** EPITECH PROJECT, 2019
** create my bag inventor
** File description:
** create_link_bag
*/

#include "my.h"

sfVector2f set_coord(char *str)
{
    char **tab = my_str_to_word_array(str, ',');
    int x = my_getnbr(tab[0]);
    int y = my_getnbr(tab[1]);
    sfVector2f pos = {x, y};

    the_free(tab);
    return (pos);
}

void init_inv_elem(game_t *gm)
{
    char **tab = read_file("config/inventory");
    int i = 0;
    char **tb = all_path(gm);
    char **tmp = NULL;
    bag_t *bag = NULL;
    int x = 0;

    while (tab[i] != NULL) {
        if (tb[x] != NULL) {
            tmp = read_file(tb[x]);
            x++;
        } else
            tmp = NULL;
        create_link_bag(&bag, tab[i], tmp);
        i++;
    }
    gm->chara.bag.bag = bag;
}

sfColor set_color(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (sfColor_fromRGBA(154, 104, 25, 1));
    i = my_getnbr(tab[2]);
    if (i == 0)
        return (sfColor_fromRGB(154, 104, 25));
    if (i == 1)
        return (sfGreen);
    if (i == 2)
        return (sfBlue);
    if (i == 3)
        return (sfColor_fromRGB(63, 2.8, 69.8));
    if (i == 4)
        return (sfYellow);
}

void create_link_bag(bag_t **bag, char *str, char **tp)
{
    char **tab = my_str_to_word_array(str, ' ');
    bag_t *tmp = (*bag);
    bag_t *new = malloc(sizeof((*new)));
    sfVector2f pos = set_coord(tab[0]);
    sfVector2f size = set_coord(tab[1]);
    sfColor color = set_color(tp);

    new->shape = my_create_shape(size, pos, color);
    new->ps = pos;
    new->pos = pos;
    new->txt = init_text(tp);
    new->next = NULL;
    if ((*bag) == NULL)
        (*bag) = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    the_free(tab);
}
