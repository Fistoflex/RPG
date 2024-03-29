/*
** EPITECH PROJECT, 2019
** init perso stat
** File description:
** init_perso_stat
*/

#include "my.h"

statistics_t *init_stat(game_t *gm, char *file)
{
    char *path = my_strcat(gm->chara.path.slot, file, KEEP, KEEP);
    char **tab = read_file(path);
    statistics_t *stat = malloc(sizeof(*stat));

    stat->name = tab[0];
    stat->hpi = my_getnbr(tab[1]);
    stat->hp = init_normal_hp(my_getnbr(tab[1]), gm);
    stat->lvl = my_getnbr(tab[2]);
    stat->dmg = my_getnbr(tab[3]);
    stat->shield = my_getnbr(tab[4]);
    return (stat);
}