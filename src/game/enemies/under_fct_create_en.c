/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

void next_init(list_emi_t **enemies, game_t *gm)
{
    put_in_enemies(enemies, set_up_enemie
                    (4000, 4100, gm, "picture/goblinsword.png"));
    put_in_enemies(enemies, set_up_enemie
                    (4000, 4200, gm, "picture/goblinsword.png"));
    put_in_enemies(enemies, set_up_enemie
                    (4000, 4000, gm, "picture/goblinsword.png"));
    put_in_enemies(enemies, set_up_enemie
                    (3500, 3500, gm, "picture/goblinsword.png"));
}
