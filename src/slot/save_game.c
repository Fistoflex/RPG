/*
** EPITECH PROJECT, 2019
** save
** File description:
** save
*/

#include "my.h"

void    redirec_out(char **tab, char *path)
{
    int fd;
    pid_t pid;
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

    str = my_strcat(str, path.body, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hair, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hat, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.torso, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.shoulder, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.hands, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.legs, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, path.feet, FREE, FREE);
    return (str);
}

char **init_str_save(char *coord, game_t *gm)
{
    char *str = NULL;
    char **tab = NULL;

    str = my_strcat(str, gm->chara.name, KEEP, KEEP);
    str = my_strcat(str, ";", FREE, KEEP);
    str = my_strcat(str, coord, FREE, FREE);
    str = my_strcat(str, ";", FREE, KEEP);
    str = cat_path(str, gm);
    tab = my_str_to_word_array(str, ';');
    free(str);
    return (tab);
}

void    save_stuff(game_t *gm)
{
    char *path = my_strdup(gm->chara.path.slot, FREE);
    char *tp = NULL;
    char *file[] = {"stat_slot.txt", "stuff.txt", NULL};
    char *tmp[] = {"activate", NULL};
    char *coord = NULL;
    char **tab = NULL;

    tp = my_strcat(path, file[0], KEEP, KEEP);
    redirec_out(tmp, tp);
    tp = NULL;
    tp = my_strcat(path, file[1], FREE, KEEP);
    coord = my_itoa((int)gm->chara.pos.x);
    coord = my_strcat(coord, " ", FREE, KEEP);
    coord = my_strcat(coord, my_itoa((int)gm->chara.pos.y), FREE, KEEP);
    tab = init_str_save(coord, gm);
    redirec_out(tab, tp);
    free(tp);
    the_free(tab);
}

void    save_game(game_t *gm)
{
    save_stuff(gm);
}
