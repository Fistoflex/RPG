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

void    display_slots(sfRenderWindow *wind, game_t *gm)
{
    slot_t *slot = gm->slot;

    while (slot != NULL) {
        if (my_over_slot(slot->sp1, slot->sp2, gm) == 1) {
            sfSprite_setPosition(slot->sp2, slot->pos);
            sfRenderWindow_drawSprite(wind, slot->sp2, NULL);
        } else {
            sfSprite_setPosition(slot->sp1, slot->pos);
            sfRenderWindow_drawSprite(wind, slot->sp1, NULL);
        }
        slot = slot->next;
    }
}

int slot_is_select(sfSprite *sp1, sfSprite *sp2, game_t *gm)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sp1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sp2);

    if (sfFloatRect_contains(&rect1, gm->mouse.button.x, gm->mouse.button.y))
        return (1);
    else if (sfFloatRect_contains(&rect2, gm->mouse.button.x, gm->mouse.button.y))
        return (1);
    return (0);
}

char    *slot_select(game_t *gm, int *select)
{
    slot_t *slot = gm->slot;

    while (slot != NULL) {
        if (slot_is_select(slot->sp1, slot->sp2, gm) == 1) {
            (*select) = 1;
            return (slot->path);
        }
        slot = slot->next;
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
    gm->chara.path.body = my_strdup(tab[2], KEEP);
    gm->chara.hair = ch[1].sp;
    gm->chara.path.hair = my_strdup(tab[3], KEEP);
    gm->chara.hat = ch[2].sp;
    gm->chara.path.hat = my_strdup(tab[4], KEEP);
    gm->chara.torso = ch[3].sp;
    gm->chara.path.torso = my_strdup(tab[5], KEEP);
    gm->chara.shoulder = ch[4].sp;
    gm->chara.path.shoulder = my_strdup(tab[6], KEEP);
    gm->chara.hands = ch[5].sp;
    gm->chara.path.hands = my_strdup(tab[7], KEEP);
    gm->chara.legs = ch[6].sp;
    gm->chara.path.legs = my_strdup(tab[8], KEEP);
    gm->chara.feet = ch[7].sp;
    gm->chara.path.feet = my_strdup(tab[9], KEEP);
    gm->chara.path.slot = my_strdup(path, KEEP);
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
    
    chara.name = my_strdup(tab[0], KEEP);
    while (tab[i] != NULL) {
        ch[x].sp = insert_stuff(ch[x].sp, tab[i]);
        x++;
        i++;
    }
    gm->chara.pos = pos;
    init_the_struct_chara(ch, gm, tab, path);
}

void set_game_player(game_t *gm, char *path, char **file)
{
    init_stuff(gm, path, file);
}

void    set_slot_elem(char *path, game_t *gm)
{
    char *file[] = {"stat_slot.txt", "stuff.txt", NULL};
    char *comp = my_strcat(path, file[0], KEEP, KEEP);
    char **tab = read_file(comp);;

    if (my_strcmp(tab[0], "activate") == 0)
        set_game_player(gm, path, file);
    else {
        gm->chara.path.slot = path;
        gm->state = CHOICE;
    }
}

void    my_slot(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;
    char *path = NULL;
    int select = 0;

    if (gm->state == SLOT && destroy == 0)
        init_slot(gm);
    if (gm->state == SLOT) {
        display_slots(wind, gm);
        path = slot_select(gm, &select);
        if (select == 1)
            set_slot_elem(path, gm);
        destroy = 1;
    }
    if (gm->state != SLOT && destroy == 1) {
        destroy = 0;
    }
}
