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
    char *name;
    heal_t *hp;
    int hpi;
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

typedef struct itm_s {
    sfVector2f pos;
    sfSprite *sp;
    char *path;
    char **tab;
    text_t txt;
}itm_t;


typedef struct s_bag {
    int state;
    sfVector2f ps;
    sfVector2f pos;
    item_t item;
    text_t txt;
    itm_t itm;
    sfRectangleShape *shape;
    struct s_bag *next;
} bag_t;

#endif