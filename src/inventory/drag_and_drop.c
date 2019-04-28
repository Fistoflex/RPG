/*
** EPITECH PROJECT, 2019
** drag and drop
** File description:
** drag_and_drop
*/

#include "my.h"

void change_state()
{
    /*prende les states de l'item, et changer les states du perso*/
}

void drag_mode()
{
    if (event.type == sfMouseMoveEvent) {
        /*mettre a jour les vecteur de drag*/
        /*move iteme grace a la pos de la souris*/
    }
}

int move_item_in_square()
{
    /*move le sprite dans l'amplacement préçie, check si impact les states*/
    /*si il ne detect pas de slot pas dans la range ->move vers pos d'origine*/
}

void drag_and_drop(game_t *gm)
{
    sfVector2i mouse = gm->mouse.button;
    static int drag = FALSE;
    sfFloatRect rect;

    while (drag == FALSE) {
        rect = sfRectangleShape_getGlobalBounds(gm->chara.bag->s_rect);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
            drag_mode();
            drag = TRUE;
        }
        gm->chara.bag = gm->chara.bag->next;
    }
    if (drag == TRUE && sfMouse_isButtonPressed(sfMouseLeft) == sfFalse) {
        move_time_in_square();
        drag = FALSE;
    }
}