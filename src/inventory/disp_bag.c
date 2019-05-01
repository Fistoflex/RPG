/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

void    dis_elem(sfRenderWindow *wind, game_t *gm)
{
    bag_t *bag = gm->chara.bag.bag;

    bag->ps = position(gm->chara.bag.coord[0]);
    elem_to_disp(wind, &bag, gm->chara.hair, gm);
    elem_to_disp(wind, &bag, gm->chara.hat, gm);
    bag->ps = position(gm->chara.bag.coord[1]);
    elem_to_disp(wind, &bag, gm->chara.torso, gm);
    bag->ps = position(gm->chara.bag.coord[2]);
    elem_to_disp(wind, &bag, gm->chara.legs, gm);
    bag->ps = position(gm->chara.bag.coord[3]);
    elem_to_disp(wind, &bag, gm->chara.feet, gm);
    bag->ps = position(gm->chara.bag.coord[4]);
    elem_to_disp(wind, &bag, gm->chara.hands, gm);
}

bag_t *jump_list(bag_t *bag, int n)
{
    int i = 0;

    while (i != n) {
        bag = bag->next;
        i++;
    }
    return (bag);
}

void    disp_bag_elem(sfRenderWindow *wind, bag_t **bag, sfSprite *sp, game_t *gm)
{
    sfIntRect rect = {0, 654, 64, 50};
    sfFloatRect rec;

    if (sp != NULL) {
        rec = sfRectangleShape_getGlobalBounds((*bag)->shape);
        disp_elm(wind, sp, rect, (*bag)->itm.pos);
        if (sp != NULL && sfFloatRect_contains(&rec, gm->mouse.moved.x, gm->mouse.moved.y)) {
            printf("rec:%f %f\n", rec.left, rec.top);
            draw_txt(wind, (*bag)->itm.txt);
        }
    }
    (*bag) = (*bag)->next;
}

void disp_bag(sfRenderWindow *wind, game_t *gm)
{
    bag_t *bag = jump_list(gm->chara.bag.bag, 14);

    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
    disp_bag_elem(wind, &bag, bag->itm.sp, gm);
}