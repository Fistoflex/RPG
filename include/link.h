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

typedef struct s_choice
{
    int state_iteme;
    int state_link;
    char *str;
    sfSprite *iteme_sprite;
    struct s_choice *next;
    struct s_choice *prev;
} choice_t;

#endif
