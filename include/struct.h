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
    sfClock *emi_clk;
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
} view_t;

typedef struct s_info_tiles {
    sfVector2u tileSize;
    int *tiles;
    sfTexture *tileset;
    int width;
    int height;
    sfVertexArray *vertices;
    sfRenderStates *states;
}tiles_t;

typedef struct s_tiled_map {
    tiles_t *collision;
    tiles_t *layer1;
    tiles_t *layer2;
}tiled_t;

typedef struct s_collision {
    int north;
    int south;
    int est;
    int west;
}colli_t;

typedef struct s_rectangle_shape {
    sfRectangleShape *s;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
}rect_shape_t;

typedef struct s_circle_shape {
    sfCircleShape *c;
    sfVector2f pos;
    float raduis;
    sfColor color;
}circle_shape_t;

typedef struct s_emi {
    rect_shape_t shape;
    circle_shape_t circle;
}emi_t;

typedef struct s_player_shape {
    rect_shape_t shape;
    rect_shape_t wp;
}player_t;

typedef struct s_list_emi {
    emi_t enemie;
    struct s_list_emi *next;
}list_emi_t;

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
    tiled_t tiles;
    colli_t colli;
    list_emi_t *enemies;
    player_t hitbox;
}game_t;

#endif
