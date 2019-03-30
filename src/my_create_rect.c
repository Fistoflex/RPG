/*
** EPITECH PROJECT, 2018
** my_create_rect
** File description:
** create rect
*/

#include <SFML/Graphics.h>

sfIntRect   my_create_rect(int h, int w, int t, int l)
{
    sfIntRect   rect;

    rect.top = t;
    rect.left = l;
    rect.width = w;
    rect.height = h;
    return (rect);
}
