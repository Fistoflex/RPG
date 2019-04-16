/*
** EPITECH PROJECT, 2019
** cust
** File description:
** cust
*/

#include "my.h"

sfFont  *my_font_(char *path)
{
    return (sfFont_createFromFile(path));
}

void    display_prompt(char *tmp, sfRenderWindow *wind, char *str, game_t *gm)
{
    sfSprite *prompt = my_create_sprite("picture/prompt.png", sfFalse);
    static int i = 0;
    sfVector2f pos = {350, 850};
    sfFont  *font = my_font_("font/a.ttf");

    if (i == 0) {
        gm->chara.nm = create_txt(tmp, font, 33, pos);
        i = 1;
    }
    sfRenderWindow_drawSprite(wind, prompt, NULL);
    if (str != NULL && my_strcmp(tmp, str) != 0)
        gm->chara.nm = create_txt(tmp, font, 33, pos);
    sfText_setColor(gm->chara.nm, sfWhite);
    sfRenderWindow_drawText(wind, gm->chara.nm, NULL);
}

void my_customize(sfRenderWindow *wind, game_t *gm, list_t **list, sfEvent evt)
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
            gm->state = GAME;
            gm->key.enter = NOT_PUSHED;
        }
        save_my_choice(wind, (*list), gm);
        str = my_strdup(tmp, KEEP);
        tmp = prompt(gm, evt);
        if (tmp != NULL) {
            display_prompt(tmp, wind, str, gm);
        }
        choice = 1;
    } else
        if (gm->state == CHOICE && choice == 1)
            gm->state = GAME;
}
