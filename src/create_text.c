/*
** EPITECH PROJECT, 2019
** create txt
** File description:
** create txt
*/

#include "my.h"

sfText  *create_txt(char *name, sfFont *font, int size, sfVector2f position)
{
    sfText  *text;

    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    sfText_setString(text, name);
    return (text);
}