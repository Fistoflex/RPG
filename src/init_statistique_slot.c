/*
** EPITECH PROJECT, 2019
** init my statiqtique sav
** File description:
** init_statistique_slot
*/

#include "my.h"

statistics_t init_statistique(char *file)
{
    char **tab = read_file(file);
    statistics_t stat;

    stat.name = my_strdup(tab[0], KEEP);
    stat.hp = init_normal_hp(my_getnbr(tab[1]));
    stat.lvl = my_getnbr(tab[2]);
    stat.dmg = my_getnbr(tab[3]);
    stat.shield = my_getnbr(tab[4]);
    return (stat);
}

/* void write_stat(statistics_t stat)
{
    int n = 0;
    char **tab = malloc(sizeof(char *) * 6);

    tab[0] = my_strdup(stat.name, KEEP);
    tab[1] = my_itoa(my_list_len(stat.hp));
    tab[2] = my_itoa(stat.lvl);
    tab[3] = my_itoa(stat.dmg);
    tab[4] = my_itoa(stat.shield);
    tab[5] = NULL;
    redirec_out(tab, "config/save/statistique_player.txt");
    free_array(tab);
}*/
