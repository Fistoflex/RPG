/*
** EPITECH PROJECT, 2019
** make map
** File description:
** init and draw map
*/

#include "my.h"

sfVector2f set_2f(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

void init_my_map(tiled_t *tiles)
{
    tiles->layer1 = malloc(sizeof(tiles_t));
    tiles->layer1->width = 100;
    tiles->layer1->height = 100;
    tiles->layer1->tiles = NULL;
    tiles->layer1->tileset = NULL;
    tiles->layer1->vertices = NULL;
    init_layer(tiles->layer1, "src/tiled/map/colision");
    if (load_map(tiles->layer1, "picture/env/colision.jpg") == FALSE)
        my_putstr_error("Failed to load map.\n");
}

void init_layer(tiles_t *tiles, char *tiles_path)
{
    tiles->tiles = get_tiles(tiles_path);
    tiles->tileSize.x = 32;
    tiles->tileSize.y = 32;
    tiles->vertices = sfVertexArray_create();
    tiles->states = init_states(tiles);
}

void draw_map(sfRenderWindow *wind, game_t *gm, char *asset_path)
{
    sfRenderWindow_drawVertexArray(wind, gm->tiles.layer1->vertices,
                                init_states(gm->tiles.layer1));
}

void my_map(sfRenderWindow *wind, game_t *gm)
{
    if (gm->state != GAME)
        return;
    draw_map(wind, gm, NULL);
}