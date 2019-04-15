/*
** EPITECH PROJECT, 2019
** keyboard guide
** File description:
** keyboard_guide
*/

#include "my.h"

settings_t init_my_rect_guide(int x, int y)
{
    settings_t set;

    set.size = set_shape_size(150, 150);
    set.pos = set_shape_position(600, 200);
    set.rect = sfRectangleShape_create();
    set.rectangle = init_the_button_rectangle(192, 225, 0, 10);
    return (set);
}

sfText *create_the_txt(char *str, int x, int y)
{
    sfFont *font = sfFont_createFromFile("font/a.ttf");
    sfVector2f pos = {x, y};

    return (create_txt(str, font, 10, pos));
}

void init_my_guide(game_t *gm)
{
    gm->k_guide.k_esc = init_my_rect_guide(10, 10);
    gm->k_guide.k_esc.txt = create_the_txt("Escape", 10, 10);
    gm->k_guide.k_tab = init_my_rect_guide(20, 20);
    gm->k_guide.k_tab.txt = create_the_txt("Tabulation", 20, 20);
    gm->k_guide.k_spell_o = init_my_rect_guide(30, 30);
    gm->k_guide.k_spell_o.txt = create_the_txt("spell_o", 30, 30);
    gm->k_guide.k_spell_tw = init_my_rect_guide(40, 40);
    gm->k_guide.k_spell_tw.txt = create_the_txt("spell_tw", 40, 40);
    gm->k_guide.k_spell_tr = init_my_rect_guide(50, 50);
    gm->k_guide.k_spell_tr.txt = create_the_txt("spell_tr", 50, 50);
    gm->k_guide.k_e = init_my_rect_guide(20, 40);
    gm->k_guide.k_e.txt = create_the_txt("E", 20, 40);
    gm->k_guide.k_i = init_my_rect_guide(60, 60);
    gm->k_guide.k_i.txt = create_the_txt("i", 60, 60);
    gm->k_guide.k_m = init_my_rect_guide(60, 60);
    gm->k_guide.k_m.txt = create_the_txt("map", 60, 60);
    gm->k_guide.k_dir = init_my_rect_guide(200, 200);
    gm->k_guide.k_dir.txt = create_the_txt("Dir", 200, 200);
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

    if (gm->state == GUI && destroy == FALSE)
        init_my_guide(gm);
    if (gm->state == GUI) {
        my_action(wind, gm);
        destroy = TRUE;
    }
    if (gm->state != GUI && destroy == TRUE) {
        sfRectangleShape_destroy(gm->set.rect);
        destroy = FALSE;
    }
}