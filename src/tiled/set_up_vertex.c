/*
** EPITECH PROJECT, 2019
** set_up_vertex
** File description:
** set up vertex quad
*/

#include "my.h"

sfVector2f set_2f(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

sfVertex *set_up_quad_pos(info_map_t *info, int i, int j, sfVertex *quad)
{
    quad[0].position = set_2f(i * info->tileSize.x, j *
                            info->tileSize.y);
    quad[1].position = set_2f((i + 1) * info->tileSize.x, j *
                            info->tileSize.y);
    quad[2].position = set_2f((i + 1) * info->tileSize.x, (j + 1) *
                            info->tileSize.y);
    quad[3].position = set_2f(i * info->tileSize.x, (j + 1) *
                            info->tileSize.y);
    return (quad);
}

sfVertex *set_up_quad_tex(info_map_t *info, int tv, int tu, sfVertex *quad)
{
    quad[0].texCoords = set_2f(tu * info->tileSize.x, tv *
                            info->tileSize.y);
    quad[1].texCoords = set_2f((tu + 1) * info->tileSize.x, tv *
                            info->tileSize.y);
    quad[2].texCoords = set_2f((tu + 1) * info->tileSize.x, (tv + 1) *
                            info->tileSize.y);
    quad[3].texCoords = set_2f(tu * info->tileSize.x, (tv + 1) *
                            info->tileSize.y);
    return (quad);
}