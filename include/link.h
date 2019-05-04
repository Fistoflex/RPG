/*
** EPITECH PROJECT, 2019
** link h
** File description:
** link_list
*/

#ifndef __LINK_H_
#define __LINK_H__

#include "key_board.h"
#include "my.h"

typedef struct s_choice {
    int state_iteme;
    int state_link;
    char *str;
    char *path;
    sfSprite *iteme_sprite;
    struct s_choice *next;
    struct s_choice *prev;
} choice_t;

typedef struct s_list {
    choice_t *iteme;
    int state_link;
    struct s_list *next;
    struct s_list *prev;
} list_t;

typedef struct s_step {
    list_t *list;
    struct s_step *next;
    struct s_step *prev;
} all_step_t;

#endif