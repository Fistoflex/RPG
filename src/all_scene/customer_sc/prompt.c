/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** get player name
*/

#include "my.h"

void prompt(sfEvent evt, game_t *gm)
{
    sfString str = NULL;
    sfText text = NULL;

    if (evt.type == sfEvtTextEntered && evt.text.unicode < 128) {
        printf("char get ---> %c\n", evt.text.unicode);
    }
}