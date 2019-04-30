/*
** EPITECH PROJECT, 2019
** item
** File description:
** item
*/

#ifndef ITEM_H_
#define ITEM_H_

typedef struct s_stat {
    char *name;
    int hp;
    int lvl;
    int dmg;
    int shield;
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