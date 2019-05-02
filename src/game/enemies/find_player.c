/*
** EPITECH PROJECT, 2019
** find_player
** File description:
** enemies find player
*/

#include "my.h"

int has_sight(sfCircleShape *circle, rect_shape_t shape)
{
    sfFloatRect global;

    if (circle == NULL || shape.s == NULL)
        return (FALSE);
    global = sfCircleShape_getGlobalBounds(circle);
    if (sfFloatRect_contains(&global, shape.pos.x, shape.pos.y))
        return (TRUE);
    return (FALSE);
}

int is_in_contact(sfRectangleShape *rect, rect_shape_t shape)
{
    sfFloatRect global;

    if (rect == NULL || shape.s == NULL)
        return (TRUE);
    global = sfRectangleShape_getGlobalBounds(rect);
    if (sfFloatRect_contains(&global, shape.pos.x, shape.pos.y))
        return (TRUE);
    return (FALSE);
}

void attack(emi_t *emi, player_t *player, sfClock *clk)
{
    sfVector2f move = set_2f((player->shape.pos.x - emi->shape.pos.x) / 8,
                            (player->shape.pos.y - emi->shape.pos.y)/ 8);

    if (has_sight(emi->circle.c, player->shape) == TRUE &&
        is_in_contact(emi->shape.s, player->shape) == FALSE) {
        sfRectangleShape_move(emi->shape.s, move);
        emi->shape.pos = sfRectangleShape_getPosition(emi->shape.s);
    }
}

void attack_player(list_emi_t *enemies, player_t *player, sfClock *clk)
{
    if (my_clock(clk) > 0.1) {
        while (enemies != NULL) {
            attack(&(enemies->enemie), player, clk);
            enemies = enemies->next;
        }
        sfClock_restart(clk);
    }
}