/*
** EPITECH PROJECT, 2019
** item
** File description:
** item
*/

#ifndef ITEM_H_
#define ITEM_H_

typedef struct s_stat
{
    sfShape *range;
    char *name;
    int hp;
    int lvl;
    int dmg;
    int shield;
} statistics_t;

typedef struct s_item
{
    statistics_t *stat;
    int pos;
} item_t;

typedef struct s_bag
{
    int pos;
    int state;
    item_t item;
    sfRectangleShape *s_rect;
    struct s_bag *next;
    struct s_bag *prev;
} bag_t;

#endif