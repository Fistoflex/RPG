/*
** EPITECH PROJECT, 2019
** create_player_shape
** File description:
** create player's shape
*/

#include "my.h"

sfVector2f get_center_player(sfVector2f p_pos, sfVector2f p_size)
{
    sfVector2f pos;
    sfVector2f size = set_2f(32, 32);

    pos.x = p_pos.x + p_size.x / 2 + (size.x / 4 - 8);
    pos.y = p_pos.y + p_size.y / 2 + (size.y / 4 - 8);
    return (pos);
}

void init_player_shape(player_t *player, sfVector2f p_pos)
{
    player->shape = init_shape(set_2f(32, 32), get_center_player(p_pos,
                                set_2f(32, 32)), sfBlue);
    player->wp = init_shape(set_2f(32, 10), get_center_player(p_pos,
                                set_2f(32, 10)), sfBlue);
}

void draw_player_shape(sfRenderWindow *wind, player_t *player, sfVector2f p_pos)
{
    sfRectangleShape_setPosition(player->shape.s, get_center_player(p_pos,
                                set_2f(32, 32)));
    player->shape.pos = get_center_player(p_pos, set_2f(32, 32));
    sfRectangleShape_setPosition(player->wp.s, get_center_player(p_pos,
                                set_2f(32, 10)));
    player->wp.pos = get_center_player(p_pos, set_2f(32, 10));
}

void destroy_player_shape(player_t player)
{
    sfRectangleShape_destroy(player.shape.s);
}