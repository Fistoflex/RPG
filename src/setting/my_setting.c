/*
** EPITECH PROJECT, 2019
** setting
** File description:
** setting
*/

#include "my.h"

void reset_bt_settings(game_t *gm)
{
    sfRectangleShape_setSize(gm->set.rect, gm->set.size);
    sfRectangleShape_setPosition(gm->set.rect, gm->set.pos);
}

void mouse_settings_button(game_t *gm)
{
    sfVector2f mouse = gm->mouse.moved;
    sfVector2f size = gm->set.size;
    sfVector2f pos = gm->set.pos;

    if ((mouse.x >= pos.x && mouse.x <= pos.x + size.x) &&
        (mouse.y >= pos.y && mouse.y <= pos.y + size.y)) {
        size = set_shape_size(size.x + 20, size.y + 20);
        pos = set_shape_position(pos.x - 8, pos.y - 8);
        sfRectangleShape_setSize(gm->set.rect, size);
        sfRectangleShape_setPosition(gm->set.rect, pos);
    }
    else
        reset_bt_settings(gm);
}

void clic_settings_button(game_t *gm)
{
    sfVector2i mouse = gm->mouse.button;
    sfFloatRect rect;
    static int pressed = FALSE;

    rect = sfRectangleShape_getGlobalBounds(gm->set.rect);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y))
        pressed = TRUE;
    if (pressed == TRUE && (mouse.x == -10 && mouse.y == -10)) {
        if (gm->set.rectangle.left == 0)
            gm->set.rectangle.left += 193;
        else
            gm->set.rectangle.left -= 193;
        sfRectangleShape_setTextureRect(gm->set.rect, gm->set.rectangle);
        pressed = FALSE;
    }
}

void my_setting(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = FALSE;

    if (gm->state == SETG && destroy == FALSE)
        gm->set = init_the_scene_settings();
    if (gm->state == SETG) {
        mouse_settings_button(gm);
        clic_settings_button(gm);
        sfRenderWindow_drawSprite(wind, gm->setting, NULL);
        sfRenderWindow_drawRectangleShape(wind, gm->set.rect, NULL);
        destroy = TRUE;
    }
    if (gm->state != SETG && destroy == TRUE) {
        sfRectangleShape_destroy(gm->set.rect);
        destroy = FALSE;
    }
}
