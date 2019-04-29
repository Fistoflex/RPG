/*
** EPITECH PROJECT, 2019
** make map
** File description:
** init and draw map
*/

#include "my.h"

void draw_map(sfRenderWindow *wind, info_map_t info,
            sfRenderStates *states, char *path)
{
    load_map(&info, path);
    sfRenderWindow_drawVertexArray(wind, info.vertices, states);
}

void init_map(tiled_t *info)
{
    info->info = init_info_map("src/tiled/map/1");
}

void destroy_map(tiled_t *tiled)
{
    free(tiled);
}

void my_map(sfRenderWindow *wind, game_t *gm)
{
    draw_map(wind, gm->tiled.info, gm->tiled.info.states, "picture/grass.png");
}