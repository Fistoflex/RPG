/*
** EPITECH PROJECT, 2019
** init my statiqtique sav
** File description:
** init_statistique_slot
*/

#include "my.h"

int my_list_len(heal_t *hp)
{
    heal_t *tmp = hp;
    int n = 0;

    while (tmp != NULL) {
        n++;
        tmp = tmp->next;
    }
    return (n);
}

char *read_file(char *file)
{
    size_t size = 0;
    char *buf = NULL;
    char *clean = my_strdup("", KEEP);
    FILE *fd = fopen(file, "r");

    while (getline(&buf, &size, fd) != -1)
        clean = my_strcat(clean, buf, FREE, FREE);
    if (clean[my_strlen(clean) - 1] == '\n')
        clean[my_strlen(clean) - 1] = '\0';
    fclose(fd);
    return (clean);
}

statistics_t *init_statistique(char *file)
{
    char **tab = my_str_to_word_array(read_file(file), '\n');
    statistics_t *stat = malloc(sizeof(* stat));

    stat->name = tab[0];
    stat->hp = init_normal_hp(atoi(tab[1]));
    stat->lvl = atoi(tab[2]);
    stat->dmg = atoi(tab[3]);
    stat->shield = atoi(tab[4]);
    free_array(tab);
    return (stat);
}

void write_stat(statistics_t *stat)
{
    int n = 0;
    char **tab = malloc(sizeof(char *) * 5);

    while (n != 4) {
        tab = malloc(sizeof(char) * 1);
        n++;
    }
    tab[0] = my_itoa(my_list_len(stat->hp));
    tab[1] = my_itoa(stat->lvl);
    tab[2] = my_itoa(stat->dmg);
    tab[3] = my_itoa(stat->shield);
    tab[4] = NULL;
    redirec_out(tab, "config/save/statistique_player.txt");
    free_array(tab);
}