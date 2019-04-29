/*
** EPITECH PROJECT, 2019
** load_map
** File description:
** load map
*/

#include "my.h"

sfVertex *set_up_quad_pos(tiles_t *tiles, int i, int j, sfVertex *quad)
{
    quad[0].position = set_2f(i * tiles->tileSize.x,
                            j * tiles->tileSize.y);
    quad[1].position = set_2f((i + 1) * tiles->tileSize.x,
                            j * tiles->tileSize.y);
    quad[2].position = set_2f((i + 1) * tiles->tileSize.x,
                            (j + 1) * tiles->tileSize.y);
    quad[3].position = set_2f(i * tiles->tileSize.x,
                            (j + 1) * tiles->tileSize.y);
    return (quad);
}

sfVertex *set_up_quad_tex(tiles_t *tiles, int tv, int tu, sfVertex *quad)
{
    quad[0].texCoords = set_2f(tu * tiles->tileSize.x,
                            tv * tiles->tileSize.y);
    quad[1].texCoords = set_2f((tu + 1) * tiles->tileSize.x,
                            tv * tiles->tileSize.y);
    quad[2].texCoords = set_2f((tu + 1) * tiles->tileSize.x,
                            (tv + 1) * tiles->tileSize.y);
    quad[3].texCoords = set_2f(tu * tiles->tileSize.x,
                            (tv + 1) * tiles->tileSize.y);
    return (quad);
}

void set_up_quad(tiles_t *tiles)
{
    int tileNumber = 0;
    int tu = 0;
    int tv = 0;
    sfVertex *quad = NULL;

    for (int i = 0; i != tiles->width; ++i) {
        for (int j = 0; j != tiles->height; ++j) {
            tileNumber = tiles->tiles[i + j * tiles->width];
            tu = tileNumber %
                (sfTexture_getSize(tiles->tileset).x / tiles->tileSize.x);
            tv = tileNumber /
                (sfTexture_getSize(tiles->tileset).x / tiles->tileSize.x);
            quad = sfVertexArray_getVertex(tiles->vertices,
                                        (i + j * tiles->width) * 4);
            quad = set_up_quad_pos(tiles, i, j, quad);
            quad = set_up_quad_tex(tiles, tv, tu, quad);
        }
    }
}

int load_map(tiles_t *tiles, char *filename)
{
    if ((tiles->tileset = sfTexture_createFromFile(filename, NULL)) == NULL)
        return (FALSE);
    sfVertexArray_setPrimitiveType(tiles->vertices, sfQuads);
    sfVertexArray_resize(tiles->vertices, tiles->width * tiles->height * 4);
    set_up_quad(tiles);
    return (TRUE);
}

sfRenderStates *init_states(tiles_t *tiles)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    states->texture = tiles->tileset;
    states->shader = NULL;
    return (states);
}