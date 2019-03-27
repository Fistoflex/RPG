/*
** EPITECH PROJECT, 2019
** biggest_txt
** File description:
** biggest_txt
*/

#include "my.h"

void biggest_txt(button_t *but, float x, float y)
{
    sfVector2f pos = {x, y};

    sfText_setCharacterSize(but->txt, but->size + 10);
    sfText_setPosition(but->txt, pos);
}