/*
** EPITECH PROJECT, 2019
** character
** File description:
** character
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"

typedef struct elem_char {
    sfSprite *sp;
}elem_char_t;

typedef struct path_s {
    char *slot;
    char *body;
    char *hair;
    char *hat;
    char *torso;
    char *shoulder;
    char *hands;
    char *legs;
    char *feet;
}path_t;

typedef struct bagg_s {
    sfSprite *inv;
    bag_t bag;
}bagg_t;

typedef struct char_s {
    char *name;
    statistics_t *stat;
    bagg_t bag;
    sfText  *nm;
    sfVector2f pos;
    sfSprite *body;
    sfSprite *hair;
    sfSprite *hat;
    sfSprite *torso;
    sfSprite *shoulder;
    sfSprite *hands;
    sfSprite *legs;
    sfSprite *feet;
    path_t path;
} chara_t;

#endif
