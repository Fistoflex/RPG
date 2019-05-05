/*
** EPITECH PROJECT, 2019
** fight
** File description:
** fight
*/

#include "my.h"

void receive_dmg(statistics_t *play, int dmg)
{
    heal_t *tmp = play->hp;

    while (tmp->next != NULL && tmp->next->state != FALSE)
        tmp = tmp->next;
    tmp->state = FALSE;
}

int check_hit(int shield)
{
    if (my_random(shield) == 1)
        return (TRUE);
    return (FALSE);
}

int my_base(statistics_t *play, player_t hitbox, emi_t en, sfClock *coold)
{
    int ret = FALSE;
    sfFloatRect en_r = sfRectangleShape_getGlobalBounds(en.shape.s);
    sfFloatRect play_r = sfRectangleShape_getGlobalBounds(hitbox.shape.s);
    sfFloatRect wap_r = sfRectangleShape_getGlobalBounds(hitbox.wp.s);

    if (hitbox.state != IMN && en.state != DEF &&
    sfFloatRect_intersects(&play_r, &en_r, NULL) == sfTrue) {
        if (check_hit(play->shield) == FALSE) {
            receive_dmg(play, en.st->dmg);
            sfClock_restart(coold);
        }
    }
    if (hitbox.state == ATT &&
    sfFloatRect_intersects(&wap_r, &en_r, NULL) == sfTrue) {
        ret = TRUE;
        en.st->hpi -= play->dmg;
    }
    return (ret);
}

void my_fight(statistics_t *play, list_emi_t *en, game_t *gm)
{
    if (my_clock(gm->clock.spell) < 1)
        gm->hitbox.state = IMN;
    while (en != NULL) {
        if (my_base(play, gm->hitbox, en->enemie, gm->clock.spell) == TRUE) {
            en->enemie.shape.pos.x += 200;
            sfRectangleShape_setPosition(en->enemie.shape.s,
            en->enemie.shape.pos);
        }
        if (en->enemie.st->hpi < 0)
            en->enemie.state = DEF;
        en = en->next;
    }
}