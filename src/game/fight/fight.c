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

/*int my_base(statistics_t *play, player_t hitbox, statistics_t *en)
{
    int ret = FALSE;
    sfFloatRect play_r = sfCircleShape_getGlobalBounds(&hitbox.shape);
    sfFloatRect wap_r = sfCircleShape_getGlobalBounds(&hitbox.wp);
    sfFloatRect en_r = sfCircleShape_getGlobalBounds();

    if (hitbox.state != IMN &&
    sfFloatRect_intersects(&play_r, &en_r, NULL) == sfTrue)
        if (check_hit(play->shield) == FALSE)
            receive_dmg(play, en->dmg);
        //else
            //write BLOCK
    if (hitbox.state == IMN &&
    sfFloatRect_intersects(&en_r, &wap_r, NULL) == sfTrue) {
        en->hp -= play->dmg;
        ret = TRUE;
    }
    return (ret);
}*/

void my_fight(statistics_t *play, statistics_t *en)
{
    /*faire un clock pour timé des attacks (si le play att,
    l'en doit attendre la clock, une case du tableau doit attendre une clock), faire l'animation de l'attack */
    /*weapon, shape en collision = auto attack*/
    /*les ennemies sont en tableau de structure*/
    /*si la fonction my_base renvoie TRUE, L'ENNEMI DOIT ETRE REPONSSER*/
}