/*
** EPITECH PROJECT, 2019
** testo
** File description:
** testo csfml for the prompt
*/

#include "my.h"

void prompt(sfRenderWindow *win, game_t *gm, sfEvent event)
{
    char *str = NULL;
    sfIntRect rectangle;

    rectangle.top = 0;
    rectangle.left = 0;
    rectangle.width = 150;
    rectangle.height = 550;
    sfTexture_createFromFile("./picture/prompt.png", &rectangle);

    while (gm->key.enter == NOT_PUSHED) {
        if (str != NULL)
            printf("%s\n", str);
        if (event.type == sfEvtTextEntered)
            str = add_char(str, event.text.unicode);
    }
    gm->chara.name = str;
}