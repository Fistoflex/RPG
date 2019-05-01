/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    draw_shape(bag_t *bag, sfRenderWindow *wind)
{
    while (bag != NULL) {
        sfRenderWindow_drawRectangleShape(wind, bag->shape, NULL);
        bag = bag->next;
    }
}

void    disp_pl(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {7, 7};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
    }
}

void    elem_to_disp(sfRenderWindow *wind, bag_t **bag, sfSprite *sp, game_t *gm)
{
    sfIntRect rect = {0, 654, 64, 50};
    sfFloatRect rec;

    if (sp != NULL)
        rec = sfRectangleShape_getGlobalBounds((*bag)->shape);
    if (disp_elm(wind, sp, rect, (*bag)->ps) == TRUE) {
        if (sp != NULL && sfFloatRect_contains(&rec, gm->mouse.moved.x, gm->mouse.moved.y))
            draw_txt(wind, (*bag)->txt);
        (*bag) = (*bag)->next;
    }
}

sfVector2f position(char *str)
{
    char **tab = my_str_to_word_array(str, ' ');
    sfVector2f pos = {atoi(tab[0]), atoi(tab[1])};

    return (pos);
}

void    my_inventory(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == INV && destroy == 0) {
        init_inventory(gm);
    }
    if (gm->state == INV) {
        sfRenderWindow_drawSprite(wind, gm->chara.bag.inv, NULL);
        draw_shape(gm->chara.bag.bag, wind);
        disp_player(wind, gm);
        dis_elem(wind, gm);
        disp_bag(wind, gm);
        if (gm->key.i == PUSHED) {
            gm->state = GAME;
            gm->key.i = NOT_PUSHED;
        }
        sfRenderWindow_setView(wind, gm->view.inv);
        destroy = 1;
    }
    if (gm->state != INV && destroy == 1) {
        sfSprite_destroy(gm->chara.bag.inv);
        destroy = 0;
    }
}