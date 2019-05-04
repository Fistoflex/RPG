/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "pointer.h"
#include "my.h"

itm_t set_itm(game_t *gm, text_t txt, int state)
{
    itm_t item;
    int i = 0;
    point_bag_t fct[] = {{HEAD, &head}, {TORSO, &torso},
                        {PANTS, &pants}, {FEET, &feet},
                        {HAND, &hand}, {-1, NULL}};

    item.pos.x = 0;
    item.pos.y = 0;
    while (fct[i].state != -1) {
        if (fct[i].state == state)
            fct[i].fct(gm, &item, 0);
        i++;
    }
    item.tab = NULL;
    item.txt = copy_txt(txt);
    return (item);
}

bag_t *copy_strct(bag_t *bag, game_t *gm)
{
    bag_t *new = malloc(sizeof((*new)));

    new->state = bag->state;
    new->ps.x = 0;
    new->ps.y = 0;
    new->itm = set_itm(gm, bag->txt, new->state);
    new->shape = shape_copy(bag->shape);
    return (new);
}

bag_t *swap_elem(bag_t **bag, bag_t *tmp, game_t *gm)
{
    bag_t *new = copy_strct((*bag), gm);
    int i = 0;
    point_bag_t fct[] = {{HEAD, &head}, {TORSO, &torso},
                        {PANTS, &pants}, {FEET, &feet},
                        {HAND, &hand}, {-1, NULL}};

    (*bag)->state = tmp->state;
    while (fct[i].state != -1) {
        if (fct[i].state == tmp->state)
            fct[i].fct(gm, &tmp->itm, 1);
        i++;
    }
    (*bag)->txt = copy_txt(tmp->itm.txt);
    sfRectangleShape_destroy((*bag)->shape);
    (*bag)->shape = shape_copy(tmp->shape);
    return (new);
}

void copy_this(bag_t *tmp, bag_t **bag)
{
    (*bag)->state = tmp->state;
    (*bag)->itm.sp = sprite_copy(tmp->itm.path, (*bag)->itm.pos);
    (*bag)->itm.path = my_strdup(tmp->itm.path, KEEP);
    (*bag)->itm.txt = copy_txt(tmp->itm.txt);
    (*bag)->shape = shape_copy(tmp->shape);
}

void drag_and_drop(sfRenderWindow *wind, game_t *gm)
{
    bag_t *bag = gm->chara.bag.bag;
    int state = 0;

    if (gm->clik == PUSHED) {
        sfSprite_setPosition(gm->tmp->itm.sp, gm->mouse.moved);
        sfRenderWindow_drawSprite(wind, gm->tmp->itm.sp, NULL);
    }
    loop_one(gm, &bag, &state);
    while (bag != NULL && state == 1) {
        if (bag->state == gm->tmp->state && bag->itm.sp == NULL) {
            copy_this(gm->tmp, &bag);
            state = 0;
        }
        bag = bag->next;
    }
}
