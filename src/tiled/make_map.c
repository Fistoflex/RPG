/*
** EPITECH PROJECT, 2019
** make map
** File description:
** init and draw map
*/

#include "my.h"

tiles_t *set_up_layer(void)
{
    tiles_t *layer = malloc(sizeof(tiles_t));

    layer->width = 350;
    layer->height = 350;
    layer->tiles = NULL;
    layer->tileset = NULL;
    layer->vertices = NULL;
    return (layer);
}

void init_my_map(tiled_t *tiles)
{
    tiles->collision = set_up_layer();
    init_layer(tiles->collision, "src/tiled/map/colision");
    if (load_map(tiles->collision, "picture/env/all.png") == FALSE)
        my_putstr_error("Failed to load map.\n");
    tiles->layer1 = set_up_layer();
    init_layer(tiles->layer1, "src/tiled/map/layer1");
    if (load_map(tiles->layer1, "picture/env/all.png") == FALSE)
        my_putstr_error("Failed to load map.\n");
    tiles->layer2 = set_up_layer();
    init_layer(tiles->layer2, "src/tiled/map/layer2");
    if (load_map(tiles->layer2, "picture/env/all.png") == FALSE)
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

void draw_map(sfRenderWindow *wind, tiled_t tiles)
{
    sfRenderWindow_drawVertexArray(wind, tiles.layer1->vertices,
                                init_states(tiles.layer1));
    sfRenderWindow_drawVertexArray(wind, tiles.layer2->vertices,
                                init_states(tiles.layer2));
}

void my_map(sfRenderWindow *wind, game_t *gm)
{
    if (gm->state != GAME)
        return;
    draw_map(wind, gm->tiles);
}
