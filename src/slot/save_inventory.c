/*
** EPITECH PROJECT, 2019
** save
** File description:
** save
*/

#include "my.h"

char *parsing(sfText *txt)
{
    char const *str = sfText_getString(txt);
    char **tab = my_str_to_word_array((char *)str, ':');

    return (tab[1]);
}

char *set_text_to_save(text_t text)
{
    char *str = NULL;
    char *txt = parsing(text.name);

    str = my_strcat(str, txt, KEEP, KEEP);
    str = my_strcat(str, "\n", KEEP, KEEP);
    txt = parsing(text.hp);
    str = my_strcat(str, txt, KEEP, KEEP);
    str = my_strcat(str, "\n", KEEP, KEEP);
    txt = parsing(text.rank);
    str = my_strcat(str, txt, KEEP, KEEP);
    str = my_strcat(str, "\n", KEEP, KEEP);
    txt = parsing(text.dmg);
    str = my_strcat(str, txt, KEEP, KEEP);
    str = my_strcat(str, "\n", KEEP, KEEP);
    txt = parsing(text.dfs);
    str = my_strcat(str, txt, KEEP, KEEP);
    str = my_strcat(str, "\n", KEEP, KEEP);
    return (str);
}

void save_state_item(bag_t *bag, char *path)
{
    int fd = open(path, O_WRONLY | O_TRUNC);
    char *str = set_text_to_save(bag->txt);

    write(fd, str, my_strlen(str));
    close(fd);
}

void save_inventory(game_t *gm)
{
    bag_t *bag = gm->chara.bag.bag;
    int i = 0;
    char **tab = all_path(gm);

    while (tab[i] != NULL) {
        save_state_item(bag, tab[i]);
        i++;
        bag = bag->next;
    }
}