/*
** EPITECH PROJECT, 2019
** put_in_tiled
** File description:
** put in tiled_t
*/

#include "my.h"

info_map_t init_info_map(char *tiles)
{
    info_map_t elem;

    elem.tiles = get_tiles(tiles);
    elem.tileSize.x = 32;
    elem.tileSize.y = 32;
    elem.vertices = sfVertexArray_create();
    elem.states = init_states(elem);
    return (elem);
}