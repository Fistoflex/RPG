/*
** EPITECH PROJECT, 2019
** slot
** File description:
** slot
*/

#include "my.h"

sfSprite   *insert_stuff(sfSprite *sp, char *str)
{
    if (my_strcmp(str, "none") == 0)
        sp = NULL;
    else
        sp = my_create_sprite(str, sfFalse);
    return (sp);
}

void    init_the_struct_chara(elem_char_t *ch, game_t *gm,
                                char **tab, char *path)
{
    gm->chara.body = ch[0].sp;
    gm->chara.path.body = my_strdup(tab[2], FREE);
    gm->chara.hair = ch[1].sp;
    gm->chara.path.hair = my_strdup(tab[3], FREE);
    gm->chara.hat = ch[2].sp;
    gm->chara.path.hat = my_strdup(tab[4], FREE);
    gm->chara.torso = ch[3].sp;
    gm->chara.path.torso = my_strdup(tab[5], FREE);
    gm->chara.shoulder = ch[4].sp;
    gm->chara.path.shoulder = my_strdup(tab[6], FREE);
    gm->chara.hands = ch[5].sp;
    gm->chara.path.hands = my_strdup(tab[7], FREE);
    gm->chara.legs = ch[6].sp;
    gm->chara.path.legs = my_strdup(tab[8], FREE);
    gm->chara.feet = ch[7].sp;
    gm->chara.path.feet = my_strdup(tab[9], FREE);
    gm->chara.wp = ch[8].sp;
    gm->chara.path.wp = my_strdup(tab[10], FREE);
    gm->chara.path.slot = my_strdup(path, FREE);
    gm->state = GAME;
}

chara_t init_null(void)
{
    chara_t ch;

    ch.body = NULL;
    ch.hair = NULL;
    ch.hat = NULL;
    ch.torso = NULL;
    ch.shoulder = NULL;
    ch.hands = NULL;
    ch.legs = NULL;
    ch.feet = NULL;
    return (ch);
}

void init_stuff(game_t *gm, char *path, char **file)
{
    char *comp = my_strcat(path, file[1], KEEP, KEEP);
    char **tab = read_file(comp);
    char **tmp = my_str_to_word_array(tab[1], ' ');
    sfVector2f pos = {my_getnbr(tmp[0]), my_getnbr(tmp[1])};
    chara_t chara = init_null();
    elem_char_t ch[] = {{chara.body}, {chara.hair}, {chara.hat}, {chara.torso},
                {chara.shoulder}, {chara.hands}, {chara.legs}, {chara.feet}, {NULL}};
    int i = 2;
    int x = 0;

    gm->chara.name = my_strdup(tab[0], FREE);
    while (tab[i] != NULL) {
        ch[x].sp = insert_stuff(ch[x].sp, tab[i]);
        x++;
        i++;
    }
    gm->chara.pos = pos;
    init_the_struct_chara(ch, gm, tab, path);
    free(tab);
    the_free(tmp);
}

void    set_slot_elem(char *path, game_t *gm)
{
    char *file[] = {"stat_slot.txt", "stuff.txt", NULL};
    char *comp = my_strcat(path, file[0], KEEP, KEEP);
    char **tab = read_file(comp);

    if (my_strcmp(tab[0], "activate") == 0)
        init_stuff(gm, path, file);
    else {
        gm->chara.path.slot = my_strdup(path, FREE);
        gm->state = CHOICE;
    }
    the_free(tab);
}

void my_slot(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;
    char *path = NULL;
    int select = 0;

    set_slot_game(gm, destroy);
    if (gm->state == SLOT) {
        display_slots(wind, gm->one);
        display_slots(wind, gm->two);
        display_slots(wind, gm->three);
        path = slot_select(gm->one, &select, path, gm);
        path = slot_select(gm->two, &select, path, gm);
        path = slot_select(gm->three, &select, path, gm);
        if (select == 1)
            set_slot_elem(path, gm);
        destroy = 1;
    }
    if (gm->state != SLOT && destroy == 1) {
        destroy = 0;
    }
}
