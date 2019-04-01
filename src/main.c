/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = set_videomode();
    game_t gm;
    list_t *list = NULL;

    list = init_my_custome();
    gm = init_struct_game(window, video_mode);
    window = sfRenderWindow_create(video_mode, "My Defender",
                                    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    is_open(window, gm, list);
    sfMusic_destroy(gm.sound);
    sfRenderWindow_destroy(window);
    return (0);
}
