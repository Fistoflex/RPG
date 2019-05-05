/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = set_videomode();
    game_t gm;
    list_t *list = NULL;

    list = init_my_custome();
    srand(time(NULL));
    gm = init_struct_game();
    gm.custom_step = CHOICE;
    window = sfRenderWindow_create(video_mode, "My RPG",
                                    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    is_open(window, gm, list);
    sfMusic_destroy(gm.sound);
    sfRenderWindow_destroy(window);
    return (0);
}
