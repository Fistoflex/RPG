/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

sfVector2f set_coord(char *str)
{
    char **tab = my_str_to_word_array(str, ',');
    int x = atoi(tab[0]);
    int y = atoi(tab[1]);
    sfVector2f pos = {x, y};

    the_free(tab);
    return (pos);
}

sfColor set_color(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (sfColor_fromRGBA(154, 104, 25, 1));
    i = atoi(tab[2]);
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

text_t init_text(char **tab)
{
    text_t txt;
    char **tmp = read_file("config/save/names.txt");
    int i = 0;
    sfFont *font = sfFont_createFromFile("font/b.ttf");
    sfVector2f pos = {458, 600};
    sfVector2f coord = {454, 595};
    sfVector2f size = {400, 200};

    if (tab != NULL)
        while (tab[i] != NULL && tmp[i] != NULL) {
            tmp[i] = my_strcat(tmp[i], tab[i], KEEP, KEEP);
            i++;
        }
    txt.name = create_txt(tmp[0], font, 33, pos);
    pos.y += 30;
    txt.hp = create_txt(tmp[1], font, 33, pos);
    pos.y += 30;
    txt.rank = create_txt(tmp[2], font, 33, pos);
    pos.y += 30;
    txt.dmg = create_txt(tmp[3], font, 33, pos);
    pos.y += 30;
    txt.dfs = create_txt(tmp[4], font, 33, pos);
    txt.shape = my_create_shape(size, coord, sfColor_fromRGBA(0, 0, 0, 80));
    return (txt);
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

char **all_path(void)
{
    char **tab = malloc(sizeof(char *) * 5);

    tab[0] = "config/save/hair.txt";
    tab[1] = "config/save/torso.txt";
    tab[2] = "config/save/legs.txt";
    tab[3] = "config/save/feet.txt";
    tab[4] = NULL;
    return (tab);
}

void    init_inv_elem(game_t *gm)
{
    char **tab = read_file("config/inventory");
    int i = 0;
    char **tb = all_path();
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

void init_inventory(game_t *gm)
{
    sfVector2f pos = {410, 0};
    sfVector2f size = {3, 3};
    static int i = 0;

    if (i == 0) {
        init_inv_elem(gm);
        i++;
    }
    gm->chara.bag.inv = my_create_sprite("picture/item/MicrosoftTeams-image.png", sfFalse);
    sfSprite_setPosition(gm->chara.bag.inv, pos);
    sfSprite_scale(gm->chara.bag.inv, size);
}