/*
** EPITECH PROJECT, 2019
** keyboard guide
** File description:
** keyboard_guide
*/

#include "my.h"

settings_t init_my_rect_guide(int x, int y, int size_x, int size_y)
{
    settings_t set;

    set.size = set_shape_size(size_x, size_y);
    set.pos = set_shape_position(x, y);
    set.rect = sfRectangleShape_create();
    set.rectangle = init_the_button_rectangle(192, 225, 0, 10);
    sfRectangleShape_setPosition(set.rect, set.pos);
    sfRectangleShape_setSize(set.rect, set.size);
    sfRectangleShape_setFillColor(set.rect, sfRed);
    return (set);
}

sfText *create_the_txt(char *str, int x, int y)
{
    sfFont *font = sfFont_createFromFile("font/a.ttf");
    sfVector2f pos = {x, y};

    return (create_txt(str, font, 100, pos));
}

void init_my_guide(game_t *gm)
{
    gm->k_guide.k_esc = init_my_rect_guide(150, 210, 90, 50);
    gm->k_guide.k_esc.txt = create_the_txt("Escape", 700, 100);
    gm->k_guide.k_tab = init_my_rect_guide(151, 398, 140, 90);
    gm->k_guide.k_tab.txt = create_the_txt("Change companion", 500, 100);
    gm->k_guide.k_spell_o = init_my_rect_guide(266, 288, 83, 83);
    gm->k_guide.k_spell_o.txt = create_the_txt("Spell 1", 700, 100);
    gm->k_guide.k_spell_tw = init_my_rect_guide(380, 290, 83, 83);
    gm->k_guide.k_spell_tw.txt = create_the_txt("Spell 2", 700, 100);
    gm->k_guide.k_spell_tr = init_my_rect_guide(490, 290, 83, 83);
    gm->k_guide.k_spell_tr.txt = create_the_txt("Spell 3", 700, 100);
    gm->k_guide.k_e = init_my_rect_guide(546, 398, 83, 83);
    gm->k_guide.k_e.txt = create_the_txt("Interact", 700, 100);
    gm->k_guide.k_i = init_my_rect_guide(1110, 398, 83, 83);
    gm->k_guide.k_i.txt = create_the_txt("Inventory", 700, 100);
    gm->k_guide.k_m = init_my_rect_guide(1360, 506, 83, 83);
    gm->k_guide.k_m.txt = create_the_txt("Map", 700, 100);
    gm->k_guide.k_dir = init_my_rect_guide(1450, 720, 300, 100);
    gm->k_guide.k_dir.txt = create_the_txt("Move", 700, 100);
}

void my_action(sfRenderWindow *win, game_t *gm)
{
    int pressed = FALSE;

    pressed = contain(win, pressed, gm, gm->k_guide.k_dir);
    pressed = contain(win, pressed, gm, gm->k_guide.k_e);
    pressed = contain(win, pressed, gm, gm->k_guide.k_esc);
    pressed = contain(win, pressed, gm, gm->k_guide.k_i);
    pressed = contain(win, pressed, gm, gm->k_guide.k_m);
    pressed = contain(win, pressed, gm, gm->k_guide.k_spell_o);
    pressed = contain(win, pressed, gm, gm->k_guide.k_spell_tr);
    pressed = contain(win, pressed, gm, gm->k_guide.k_spell_tw);
    pressed = contain(win, pressed, gm, gm->k_guide.k_tab);
}

void keyboard_guide(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = FALSE;
    static sfSprite *key;
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {130, 200};

    gm->state = GUI;
    if (gm->state == GUI && destroy == FALSE) {
        key = my_create_sprite("picture/key_guide.png", sfFalse);
        sfSprite_setScale(key, scale);
        sfSprite_setPosition(key, pos);
        init_my_guide(gm);
    }
    sfRenderWindow_drawSprite(wind, key, NULL);
    if (gm->state == GUI) {
        my_action(wind, gm);
        destroy = TRUE;
    }
    if (gm->state != GUI && destroy == TRUE) {
        sfRectangleShape_destroy(gm->set.rect);
        destroy = FALSE;
    }
}