/*
** EPITECH PROJECT, 2019
** pointer
** File description:
** pointer
*/

#ifndef POINTER_H_
#define POINTER_H_

#include "my.h"

typedef struct key_s {
    int flag;
    int *button;
    void (*fct)(int *);
}key_s;

typedef struct stat_scn {
    int scene;
    int new_scene;
}stat_scn_t;

typedef struct bt_pause_s {
    sfText *txt;
    void (*fct)(game_t *);
}bt_pause_t;

typedef struct bt_menu_s {
    sfText *txt;
    void (*fct)(game_t *);
}bt_menu_t;

typedef struct s_way_ptr {
    int way;
    int (*ptr)(int, int);
}way_ptr_t;

typedef struct point_bag_s {
    int state;
    void (*fct)(game_t *, itm_t *, int);
}point_bag_t;

void head(game_t *gm, itm_t *item, int);
void torso(game_t *gm, itm_t *item, int);
void pants(game_t *gm, itm_t *item, int);
void feet(game_t *gm, itm_t *item, int);
void hand(game_t *gm, itm_t *item, int);

#endif