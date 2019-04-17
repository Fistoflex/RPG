/*
** EPITECH PROJECT, 2019
** cust
** File description:
** cust
*/

#include "my.h"

sfFont  *my_font(char *path)
{
    return (sfFont_createFromFile(path));
}

char *upper_case(char *tmp)
{
    int i = 0;

    while (tmp[i] != '\0') {
        if (tmp[i] >= 'a' && tmp[i] <= 'z')
            tmp[i] -= 32;
        i++;
    }
    return (tmp);
}

void    display_prompt(char *tmp, sfRenderWindow *wind, char *str, game_t *gm)
{
    sfSprite *prompt = my_create_sprite("picture/prompt.png", sfFalse);
    static int i = 0;
    sfVector2f pos = {800, 900};
    sfVector2f ps = {720, 850};
    sfFont  *font = my_font("font/a.ttf");

    if (i == 0 && tmp != NULL) {
        tmp = upper_case(tmp);
        gm->chara.nm = create_txt(tmp, font, 33, pos);
        i = 1;
    }
    sfSprite_setPosition(prompt, ps);
    sfRenderWindow_drawSprite(wind, prompt, NULL);
    if (str != NULL && my_strcmp(tmp, str) != 0) {
        tmp = upper_case(tmp);
        gm->chara.nm = create_txt(tmp, font, 33, pos);
    }
    if (tmp != NULL) {
        sfText_setColor(gm->chara.nm, sfWhite);
        sfRenderWindow_drawText(wind, gm->chara.nm, NULL);
    }
}

void my_customize(sfRenderWindow *wind, game_t *gm, list_t **list, sfEvent *evt)
{
    static int choice = 0;
    static char *tmp = NULL;
    static char *str = NULL;

    if (gm->state == CHOICE && choice == 0) {
        if (gm->key.enter == PUSHED) {
            gm->state = NAME;
            gm->key.enter = NOT_PUSHED;
        }
        (*list) = make_your_choice(wind, gm, (*list));
    } else if (gm->state == NAME) {
        if (gm->key.enter == PUSHED) {
            gm->chara.name = my_strdup(tmp, FREE);
            gm->state = GAME;
            gm->key.enter = NOT_PUSHED;
        }
        save_my_choice(wind, (*list), gm);
        str = my_strdup(tmp, KEEP);
        tmp = prompt(gm, evt);
        display_prompt(tmp, wind, str, gm);
        choice = 1;
    } else
        if (gm->state == CHOICE && choice == 1)
            gm->state = GAME;
}
