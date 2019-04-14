/*
** EPITECH PROJECT, 2019
** save
** File description:
** save
*/

#include "my.h"

void    redirec_out(char **tab, char *path)
{
    int     fd;
    pid_t   pid;
    int i = 0;
    int tmp = 0;

    fd = open(path, O_WRONLY | O_TRUNC);
    while (tab[i] != NULL) {
        write(fd, tab[i], my_strlen(tab[i]));
        write(fd, "\n", 1);
        i++;
    }
    close(fd);
}

char *cat_path(char *str, game_t *gm)
{
    path_t path = gm->chara.path;

    str = my_strcat(str, path.body, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hair, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hat, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.torso, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.shoulder, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hands, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.legs, FREE, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.feet, FREE, KEEP);
    return (str);
}

char **init_str_save(char *coord, game_t *gm)
{
    char *str = NULL;
    char **tab = NULL;

    str = my_strcat(str, "none;", KEEP, KEEP);
    str = my_strcat(str, coord, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = cat_path(str, gm);
    tab = my_str_to_word_array(str, ';');
    return (tab);
}

void    save_stuff(game_t *gm)
{
    char *path = gm->chara.path.slot;
    char *tp = NULL;
    char *file[] = {"stat_slot.txt", "stuff.txt", NULL};
    char *tmp[] = {"activate", NULL};
    char *coord = NULL;
    char **tab = NULL;

    tp = my_strcat(path, file[0], KEEP, KEEP);
    redirec_out(tmp, tp);
    tp = NULL;
    tp = my_strcat(path, file[1], KEEP, KEEP);
    coord = my_itoa(gm->chara.pos.x);
    coord = my_strcat(coord, " ", KEEP, KEEP);
    coord = my_strcat(coord, my_itoa(gm->chara.pos.y), FREE, KEEP);
    tab = init_str_save(coord, gm);
    redirec_out(tab, tp);
}

void    save_game(game_t *gm)
{
    save_stuff(gm);
}
