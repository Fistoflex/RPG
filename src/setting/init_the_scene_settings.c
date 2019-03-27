/*
** EPITECH PROJECT, 2019
** init_the_scene_settings
** File description:
** init_the_scene_settings
*/

#include "my.h"

sfVector2f set_shape_size(int x, int y)
{
    sfVector2f size;

    size.x = x;
    size.y = y;
    return (size);
}

sfVector2f set_shape_position(int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

void setting_button(settings_t *set, char *path)
{
    sfIntRect area = init_the_button_rectangle(1920, 1080, 0, 0);
    sfTexture *texture = sfTexture_createFromFile(path, &area);

    sfRectangleShape_setSize(set->rect, set->size);
    sfRectangleShape_setPosition(set->rect, set->pos);
    sfRectangleShape_setTexture(set->rect, texture, sfTrue);
    sfRectangleShape_setTextureRect(set->rect, set->rectangle);
}

settings_t init_the_scene_settings(void)
{
    settings_t set;

    set.size = set_shape_size(150, 150);
    set.pos = set_shape_position(600, 200);
    set.rect = sfRectangleShape_create();
    set.rectangle = init_the_button_rectangle(192, 225, 0, 192 * 2);
    setting_button(&set, "picture/buts.png");
    return (set);
}
