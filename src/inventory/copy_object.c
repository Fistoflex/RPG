/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"

sfRectangleShape *shape_copy(sfRectangleShape *shape)
{
    sfVector2f pos = sfRectangleShape_getPosition(shape);
    sfVector2f size = sfRectangleShape_getSize(shape);
    sfColor color = sfRectangleShape_getFillColor(shape);
    sfRectangleShape *sh =  my_create_shape(size, pos, color);

    return (sh);
}

sfText *text_copy(sfText *text)
{
    char const *str = sfText_getString(text);
    sfFont const *font = sfText_getFont(text);
    int size = sfText_getCharacterSize(text);
    sfVector2f pos = sfText_getPosition(text);
    sfText *txt = create_txt((char *)str, (sfFont *)font, size, pos);

    return (txt);
}

sfSprite *sprite_copy(char *path, sfVector2f pos)
{
    sfVector2f scale = {3, 3};
    sfIntRect rect = {0, 654, 64, 50};
    sfSprite *sp = my_create_sprite(path, sfFalse);

    sfSprite_setScale(sp, scale);
    sfSprite_setPosition(sp, pos);
    sfSprite_setTextureRect(sp, rect);
    return (sp);
}
