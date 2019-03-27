/*
** EPITECH PROJECT, 2019
** my_menu
** File description:
** my_menu
*/

#include "my.h"
#include "pointer.h"

void reset_bt_menu(game_t *gm)
{
    sfText_setColor(gm->menu.start.txt, sfWhite);
    sfText_setColor(gm->menu.setg.txt, sfWhite);
    sfText_setColor(gm->menu.exit.txt, sfWhite);
    sfText_setPosition(gm->menu.exit.txt, gm->menu.exit.pos);
    sfText_setPosition(gm->menu.setg.txt, gm->menu.setg.pos);
    sfText_setPosition(gm->menu.start.txt, gm->menu.start.pos);
    sfText_setCharacterSize(gm->menu.exit.txt, gm->menu.exit.size - 10);
    sfText_setCharacterSize(gm->menu.setg.txt, gm->menu.setg.size - 10);
    sfText_setCharacterSize(gm->menu.start.txt, gm->menu.start.size - 10);
}

int my_set_song(int sound, game_t *gm)
{
    if (sound == FALSE) {
        sfMusic_play(gm->sound);
        sound = TRUE;
    }
    return (sound);
}

void mouse_on_button(game_t *gm, sfVector2f mouse)
{
    bt_menu_t but[] = {{gm->menu.start.txt, &color_txt_start},
                        {gm->menu.exit.txt, &color_txt_exit},
                        {gm->menu.setg.txt, &color_txt_setg}, {NULL, NULL}};
    sfFloatRect rect;
    int i = 0;
    static int sound = FALSE;

    while (but[i].txt != NULL) {
        rect = sfText_getGlobalBounds(but[i].txt);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
            but[i].fct(gm);
            sound = my_set_song(sound, gm);
            return;
        }
        i++;
    }
    if (but[i].txt == NULL)
        sound = FALSE;
    reset_bt_menu(gm);
}

void my_menu(sfRenderWindow *wind, game_t *gm)
{
    static int destroy = 0;

    if (gm->state == MENU && destroy == 0)
        gm->menu = init_the_scene_menu();
    if (gm->state == MENU) {
        mouse_on_button(gm, gm->mouse.moved);
        sfRenderWindow_drawText(wind, gm->menu.start.txt, NULL);
        sfRenderWindow_drawText(wind, gm->menu.setg.txt, NULL);
        sfRenderWindow_drawText(wind, gm->menu.exit.txt, NULL);
        destroy = 1;
    }
    if (gm->state != MENU && destroy == 1) {
        sfText_destroy(gm->menu.start.txt);
        sfText_destroy(gm->menu.setg.txt);
        sfText_destroy(gm->menu.exit.txt);
        destroy = 0;
    }
}
