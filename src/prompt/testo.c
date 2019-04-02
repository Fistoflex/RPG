/*
** EPITECH PROJECT, 2019
** testo
** File description:
** testo csfml for the prompt
*/

#include "my.h"

char *prompt(sfRenderWindow *win, sfEvent event)
{
    char *str = NULL;
    sfIntRect rectangle;

    rectangle.top = 0;
    rectangle.left = 0;
    rectangle.width = 150;
    rectangle.height = 550;
    sfTexture_createFromFile("./picture/prompt.png", rectangle);

    while (gm->key->enter != PUSHED) {
        if(event.type == sfEvtTextEntered)
            printf("%c\n", event.unicode);
    {
    return (str);
}