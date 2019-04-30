/*
** EPITECH PROJECT, 2019
** item
** File description:
** item
*/

#ifndef ITEM_H_
#define ITEM_H_

typedef struct s_heal {
    int state;
    sfVector2f old_pos;
    sfVector2f pos;
    struct s_heal *next;
} heal_t;

typedef struct s_stat
{
    sfShape *range;
    sfShape *wap_range;
    char *name;
    heal_t *hp;
    int lvl;
    int dmg;
    int shield;//le shield doit etre un int, plus il est grand moins il est efficace
} statistics_t;

typedef struct s_item {
    statistics_t stat;
    int pos;
} item_t;

typedef struct text_s {
    sfText *name;
    sfText *hp;
    sfText *rank;
    sfText *dmg;
    sfText *dfs;
    sfRectangleShape *shape;
}text_t;

typedef struct s_bag {
    int pos;
    int state;
    sfVector2f ps;
    item_t item;
    text_t txt;
    sfRectangleShape *shape;
    struct s_bag *next;
} bag_t;

#endif