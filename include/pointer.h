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

#endif