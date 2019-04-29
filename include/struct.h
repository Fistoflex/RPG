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
    chara_t chara;
    int stat;
    sfVector2f pos_s;
    sfVector2f pos_p;
    sfVector2f pos_n;
    sfSprite *slot;
    char *path;
} slot_t;

typedef struct sfIntRect_contains {
    sfTexture *txtr;
    sfSprite *sp;
    sfTexture *txtr2;
    sfSprite *sp2;
    sfMusic *msc;
} intro_t;

typedef struct button_s {
    sfText *txt;
    sfVector2f pos;
    int size;
} button_t;

typedef struct menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    button_t start;
    button_t setg;
    button_t exit;
} menu_t;

typedef struct pause_s {
    button_t resume;
    button_t restart;
    button_t home;
    button_t exit;
} pause_t;

typedef struct settings_s
{
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f pos;
    sfIntRect rectangle;
    sfText *txt;
} settings_t;

typedef struct mouse_s {
    sfVector2f moved;
    sfVector2i button;
} mouse_t;

typedef struct clck_s {
    sfClock *esc;
    sfClock *anim;
    sfClock *enter;
} clck_t;

typedef struct guide {
    settings_t k_esc;
    settings_t k_tab;
    settings_t k_spell_o;
    settings_t k_spell_tw;
    settings_t k_spell_tr;
    settings_t k_e;
    settings_t k_i;
    settings_t k_m;
    settings_t k_dir;
} k_guide_t;

typedef struct view_s {
    sfView *game;
    sfView *pause;
    sfView *menu;
    sfView *inv;
}view_t;

typedef struct s_info_map {
    sfVector2u tileSize;
    int *tiles;
    sfTexture *tileset;
    int width;
    int height;
    sfVertexArray *vertices;
    sfRenderStates *states;
}info_map_t;

typedef struct s_tiled_map {
    info_map_t info;
}tiled_t;

typedef struct game_s {
    int custom_step;
    int state;
    int effect;
    char *stuff;
    slot_t one;
    slot_t two;
    slot_t three;
    sfSprite *game;
    sfSprite *setting;
    clck_t clock;
    key_board_t key;
    menu_t menu;
    chara_t chara;
    settings_t set;
    k_guide_t k_guide;
    pause_t pause;
    intro_t intro;
    mouse_t mouse;
    view_t view;
    sfMusic *sound;
    tiled_t tiled;
}game_t;

#endif
