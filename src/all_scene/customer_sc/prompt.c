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
    (*tmp) = my_strdup(str, FREE);
    gm->key.back = NOT_PUSHED;
    return (str);
}

char *prompt(sfRenderWindow *window, game_t *gm, sfEvent evt)
{
    static char *tmp = NULL;
    char buf[] = {'\0', '\0'};
    static int n = 0;

    if (gm->key.enter == PUSHED) {
        gm->chara.name = tmp;
        gm->key.enter = NOT_PUSHED;
        return (tmp);
    } else if (gm->key.back == PUSHED)
        return (the_cond_to_delete(&tmp, gm));
    if (evt.type == sfEvtTextEntered && evt.text.unicode < 128 &&
        evt.text.unicode != 8) {
        n = (n == 0) ? 1 : 0;
        if (n == 0) {
            buf[0] = evt.text.unicode;
            tmp = my_strcat(tmp, buf, KEEP, KEEP);
        }
    }
    return (tmp);
}
