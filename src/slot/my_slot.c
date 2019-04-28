/*
** EPITECH PROJECT, 2019
** slot
** File description:
** slot
*/

#include "my.h"

int my_over_slot(sfSprite *sp1, sfSprite *sp2, game_t *gm)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sp1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sp2);

    if (sfFloatRect_contains(&rect1, gm->mouse.moved.x, gm->mouse.moved.y))
        return (1);
    else if (sfFloatRect_contains(&rect2, gm->mouse.moved.x, gm->mouse.moved.y))
        return (1);
    return (0);
}

void    disp(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f pos)
{
    sfVector2f scale = {4, 4};

    if (sp != NULL) {
        sfSprite_setScale(sp, scale);
        sfSprite_setPosition(sp, pos);
        sfSprite_setTextureRect(sp, rect);
        sfRenderWindow_drawSprite(wind, sp, NULL);
    }
}

void    display_slots(sfRenderWindow *wind, slot_t slot)
{
    sfIntRect rect = {0, 654, 64, 50};

    sfSprite_setPosition(slot.slot, slot.pos_s);
    if (slot.stat == 1)
        sfRenderWindow_drawSprite(wind, slot.slot, NULL);
    else {
        disp(wind, slot.chara.body, rect, slot.pos_p);
        disp(wind, slot.chara.hair, rect, slot.pos_p);
        disp(wind, slot.chara.hat, rect, slot.pos_p);
        disp(wind, slot.chara.torso, rect, slot.pos_p);
        disp(wind, slot.chara.shoulder, rect, slot.pos_p);
        disp(wind, slot.chara.hands, rect, slot.pos_p);
        disp(wind, slot.chara.legs, rect, slot.pos_p);
        disp(wind, slot.chara.feet, rect, slot.pos_p);
        sfText_setPosition(slot.chara.nm, slot.pos_n);
        sfRenderWindow_drawText(wind, slot.chara.nm, NULL);
    }
}

int slot_is_select(sfSprite *sp1, game_t *gm)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sp1);

    if (sfFloatRect_contains(&rect1, gm->mouse.button.x, gm->mouse.button.y))
        return (1);
    return (0);
}

char    *slot_select(slot_t one, int *select, char *path, game_t *gm)
{
    slot_t slot = one;

    if (path != NULL)
        return (path);
    if (slot_is_select(slot.slot, gm) == 1) {
        (*select) = 1;
        return (slot.path);
    }
    return (NULL);
}

sfSprite   *insert_stuff(sfSprite *sp, char *str)
{
    if (my_strcmp(str, "none") == 0)
        sp = NULL;
    else
        sp = my_create_sprite(str, sfFalse);
    return (sp);
}

void    init_the_struct_chara(elem_char_t *ch, game_t *gm, char **tab, char *path)
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
    gm->chara.path.slot = my_strdup(path, FREE);
    gm->state = GAME;
}

void    init_stuff(game_t *gm, char *path, char **file)
{
    char *comp = my_strcat(path, file[1], KEEP, KEEP);
    char **tab = read_file(comp);
    char **tmp = my_str_to_word_array(tab[1], ' ');
    sfVector2f pos = {atoi(tmp[0]), atoi(tmp[1])};
    chara_t chara;
    elem_char_t ch[] = {chara.body, chara.hair, chara.hat, chara.torso,
                        chara.shoulder, chara.hands, chara.legs, chara.feet, NULL};
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

void set_game_player(game_t *gm, char *path, char **file)
{
    init_stuff(gm, path, file);
}

void    set_slot_elem(char *path, game_t *gm)
{
    char *file[] = {"stat_slot.txt", "stuff.txt", NULL};
    char *comp = my_strcat(path, file[0], KEEP, KEEP);
    char **tab = read_file(comp);

    if (my_strcmp(tab[0], "activate") == 0)
        set_game_player(gm, path, file);
    else {
        gm->chara.path.slot = my_strdup(path, FREE);
        gm->state = CHOICE;
    }
    the_free(tab);
}

void    my_slot(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;
    char *path = NULL;
    int select = 0;

    if (gm->state == SLOT && destroy == 0) {
        gm->one = set_one_slot(gm->one, 0);
        gm->two = set_one_slot(gm->two, 1);
        gm->three = set_one_slot(gm->three, 2);
    }
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
