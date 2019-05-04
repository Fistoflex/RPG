/*
** EPITECH PROJECT, 2019
** under
** File description:
** under
*/

#include "my.h"

chara_t set_chara_elem(char *tmp)
{
    char *path = my_strcat(tmp, "stuff.txt", KEEP, KEEP);
    char **tab = read_file(path);
    sfVector2f pos = {800, 900};
    sfFont  *font = my_font("font/a.ttf");
    chara_t chara = init_null();

    chara.nm = create_txt(tab[0], font, 33, pos);
    chara.body = insert_stuff(chara.body, tab[2]);
    chara.hair = insert_stuff(chara.hair, tab[3]);
    chara.hat = insert_stuff(chara.hat, tab[4]);
    chara.torso = insert_stuff(chara.torso, tab[5]);
    chara.shoulder = insert_stuff(chara.shoulder, tab[6]);
    chara.hands = insert_stuff(chara.hands, tab[7]);
    chara.legs = insert_stuff(chara.legs, tab[8]);
    chara.feet = insert_stuff(chara.feet, tab[9]);
    return (chara);
}
