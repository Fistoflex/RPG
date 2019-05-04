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
    stat->hp = init_normal_hp(atoi(tab[1]), gm);
    stat->lvl = atoi(tab[2]);
    stat->shield = atoi(tab[3]);
    return (stat);
}