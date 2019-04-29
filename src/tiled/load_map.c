/*
** EPITECH PROJECT, 2019
** load_map
** File description:
** load map
*/

#include "my.h"

sfRenderStates *init_states(info_map_t info)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    states->texture = info.tileset;
    states->shader = NULL;
    return (states);
}

sfVertex *set_up_vertex(info_map_t *info, sfVertex *quad)
{
    int i = 1;
    int j = 1;
    int tu = 0;
    int tv = 0;
    int tileNumber = 0;

    while (i != info->width) {
        for (j = 1; j != info->height; j++) {
            tileNumber = info->tiles[i + j * info->width];
            tu = tileNumber %
                (sfTexture_getSize(info->tileset).x / info->tileSize.x);
            tv = tileNumber /
                (sfTexture_getSize(info->tileset).x / info->tileSize.x);
            quad = sfVertexArray_getVertex(info->vertices,
                                            (i + j * info->width) * 4);
            quad = set_up_quad_pos(info, i, j, quad);
            quad = set_up_quad_tex(info, tv, tu, quad);
        }
    }
    return (quad);
}

int load_map(info_map_t *info, char *filename)
{
    sfVertex *quad = NULL;

    if ((info->tileset = sfTexture_createFromFile(filename, NULL)) == NULL)
        return (FALSE);
    sfVertexArray_setPrimitiveType(info->vertices, sfQuads);
    sfVertexArray_resize(info->vertices, info->width * info->height * 4);
    quad = set_up_vertex(info, quad);
    return (TRUE);
}