/*
** EPITECH PROJECT, 2019
** init_the_button_rectangle
** File description:
** init_the_button_rectangle
*/

#include "my.h"

sfIntRect init_the_button_rectangle(int width, int height, int left, int top)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}