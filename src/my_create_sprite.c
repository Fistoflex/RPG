/*
** EPITECH PROJECT, 2018
** my_create_sprite
** File description:
** create sprite
*/

#include <SFML/Graphics.h>

sfSprite    *my_create_sprite(char *name, sfBool bool)
{
    sfTexture   *texture = sfTexture_createFromFile(name, NULL);
    sfSprite    *sprite = sfSprite_create();

    if (bool == sfTrue)
        sfTexture_setRepeated(texture, bool);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
