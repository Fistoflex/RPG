/*
** EPITECH PROJECT, 2019
** my_pause
** File description:
** my_pause
*/

#include "pointer.h"
#include "my.h"

pause_t reset_button(pause_t pause)
{
    sfText_setColor(pause.resume.txt, sfWhite);
    sfText_setColor(pause.home.txt, sfWhite);
    sfText_setColor(pause.exit.txt, sfWhite);
    sfText_setColor(pause.restart.txt, sfWhite);
    sfText_setPosition(pause.exit.txt, pause.exit.pos);
    sfText_setPosition(pause.home.txt, pause.home.pos);
    sfText_setPosition(pause.restart.txt, pause.restart.pos);
    sfText_setPosition(pause.resume.txt, pause.resume.pos);
    sfText_setCharacterSize(pause.exit.txt, pause.exit.size - 10);
    sfText_setCharacterSize(pause.home.txt, pause.home.size - 10);
    sfText_setCharacterSize(pause.restart.txt, pause.restart.size - 10);
    sfText_setCharacterSize(pause.resume.txt, pause.resume.size - 10);
    return (pause);
}

pause_t over_flow(pause_t pause, sfVector2f pos, game_t *gm)
{
    bt_pause_t bt[] = {{pause.resume.txt, &resume_effect},
                        {pause.home.txt, &home_effect},
                        {pause.restart.txt, &restart_effect},
                        {pause.exit.txt, &exit_effect}, {NULL, NULL}};
    int i = 0;
    sfFloatRect rec;
    static int sound = FALSE;

    for (i = 0; bt[i].txt != NULL; i++) {
        rec = sfText_getGlobalBounds(bt[i].txt);
        if (sfFloatRect_contains(&rec, pos.x, pos.y)) {
            bt[i].fct(gm);
            sound = my_set_song(sound, gm);
            return (gm->pause);
        }
    }
    if (bt[i].txt == NULL)
        sound = FALSE;
    gm->pause = reset_button(gm->pause);
    return (gm->pause);
}

void    my_pause(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == PAUSE && destroy == 0)
        gm->pause = init_the_scene_pause();
    if (gm->state == PAUSE) {
        over_flow(gm->pause, gm->mouse.moved, gm);
        sfRenderWindow_drawText(wind, gm->pause.resume.txt, NULL);
        sfRenderWindow_drawText(wind, gm->pause.home.txt, NULL);
        sfRenderWindow_drawText(wind, gm->pause.restart.txt, NULL);
        sfRenderWindow_drawText(wind, gm->pause.exit.txt, NULL);
        destroy = 1;
    }
    if (gm->state != PAUSE && destroy == 1) {
        sfText_destroy(gm->pause.resume.txt);
        sfText_destroy(gm->pause.home.txt);
        sfText_destroy(gm->pause.exit.txt);
        sfText_destroy(gm->pause.restart.txt);
        destroy = 0;
    }
}
