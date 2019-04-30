/*
** EPITECH PROJECT, 2019
** init my text
** File description:
** init_my_text
*/

#include "my.h"

text_t set_text(text_t txt, char **tmp, sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("font/b.ttf");

    txt.name = create_txt(tmp[0], font, 33, pos);
    pos.y += 30;
    txt.hp = create_txt(tmp[1], font, 33, pos);
    pos.y += 30;
    txt.rank = create_txt(tmp[2], font, 33, pos);
    pos.y += 30;
    txt.dmg = create_txt(tmp[3], font, 33, pos);
    pos.y += 30;
    txt.dfs = create_txt(tmp[4], font, 33, pos);
    return (txt);
}

text_t init_text(char **tab)
{
    text_t txt;
    char **tmp = read_file("config/save/names.txt");
    int i = 0;
    sfVector2f pos = {458, 600};
    sfVector2f coord = {454, 595};
    sfVector2f size = {400, 200};

    if (tab != NULL)
        while (tab[i] != NULL && tmp[i] != NULL) {
            tmp[i] = my_strcat(tmp[i], tab[i], KEEP, KEEP);
            i++;
        }
    txt = set_text(txt, tmp, pos);
    txt.shape = my_create_shape(size, coord, sfColor_fromRGBA(0, 0, 0, 80));
    return (txt);
}