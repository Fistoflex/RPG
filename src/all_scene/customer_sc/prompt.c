/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** get player name
*/

#include "my.h"

char *the_cond_to_delete(char **tmp, game_t *gm)
{
    int i = 0;
    char *str = NULL;
    int size = 0;

    if ((*tmp) == NULL)
        return (NULL);
    size = my_strlen((*tmp));
    str = malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size - 1; i++) {
        str[i] = (*tmp)[i];
    }
    free((*tmp));
    str[i] = '\0';
    (*tmp) = my_strdup(str, FREE);
    gm->key.back = NOT_PUSHED;
    return (str);
}

int my_no_disp(char c)
{
    if (c >= 1 && c <= 31)
        return (1);
    return (0);
}

char *prompt(game_t *gm, sfEvent *evt)
{
    static char *tmp = NULL;
    char buf[] = {'\0', '\0'};

    if (gm->key.enter == PUSHED) {
        gm->chara.name = tmp;
        gm->key.enter = NOT_PUSHED;
        return (tmp);
    } else if (gm->key.back == PUSHED)
        return (the_cond_to_delete(&tmp, gm));
    if (evt->type == sfEvtTextEntered && evt->text.unicode < 128 &&
        my_no_disp(evt->text.unicode) != 1) {
        buf[0] = evt->text.unicode;
        tmp = my_strcat(tmp, buf, KEEP, KEEP);
        evt->type = -1;
    }
    return (tmp);
}
