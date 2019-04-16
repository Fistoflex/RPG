/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** strcu.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "key_board.h"
#include "character.h"

typedef	struct slot_s {
    sfVector2f pos;
    sfSprite *sp1;
    sfSprite *sp2;
    char *path;
    struct slot_s *next;
}slot_t;

typedef struct sfIntRect_contains {
    sfTexture *txtr;
    sfSprite *sp;
    sfTexture *txtr2;
    sfSprite *sp2;
    sfMusic *msc;
}intro_t;

typedef struct button_s {
    sfText *txt;
    sfVector2f pos;
    int size;
}button_t;

typedef struct menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    button_t start;
    button_t setg;
    button_t exit;
}menu_t;

typedef struct pause_s {
    button_t resume;
    button_t restart;
    button_t home;
    button_t exit;
}pause_t;

typedef struct settings_s
{
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f pos;
    sfIntRect rectangle;
}settings_t;

typedef struct mouse_s {
    sfVector2f moved;
    sfVector2i button;
}mouse_t;

typedef struct clck_s {
    sfClock *esc;
    sfClock *anim;
    sfClock *enter;
}clck_t;

typedef struct game_s {
    int custom_step;
    int state;
    int effect;
    char *stuff;
    sfSprite *game;
    sfSprite *setting;
    slot_t *slot;
    clck_t clock;
    key_board_t key;
    menu_t menu;
    chara_t chara;
    settings_t set;
    pause_t pause;
    intro_t intro;
    mouse_t mouse;
    sfMusic *sound;
}game_t;

#endif
