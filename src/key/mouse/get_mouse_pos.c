/*
** EPITECH PROJECT, 2019
** get_mouse_pos
** File description:
** get_mouse_pos
*/

#include "my.h"

void    get_mouse_pos(game_t *gm, sfEvent evt)
{
    if (evt.type == sfEvtMouseMoved && evt.mouseMove.type == sfEvtMouseMoved) {
        gm->mouse.moved.x = evt.mouseMove.x;
        gm->mouse.moved.y = evt.mouseMove.y;
    } else {
        if (evt.type == sfEvtMouseButtonPressed &&
            evt.mouseButton.button == sfMouseLeft) {
            gm->mouse.button.x = evt.mouseButton.x;
            gm->mouse.button.y = evt.mouseButton.y;
        } else if (evt.type == sfEvtMouseButtonReleased) {
            gm->clik = NOT_PUSHED;
            gm->mouse.release.x = evt.mouseButton.x;
            gm->mouse.release.y = evt.mouseButton.y;
        } else {
            gm->mouse.release.x = -10;
            gm->mouse.release.y = -10;
            gm->mouse.button.x = -10;
            gm->mouse.button.y = -10;
        }
    }
}
