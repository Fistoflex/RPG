/*
** EPITECH PROJECT, 2019
** collision
** File description:
** collision
*/

#include "my.h"
#include "pointer.h"

void init_collision(colli_t *colli)
{
    colli->north = FALSE;
    colli->south = FALSE;
    colli->est = FALSE;
    colli->west = FALSE;
}

int is_in_collision(tiles_t *layer1, int player_pos, int way)
{
    way_ptr_t tab[] = {{NORTH, &get_north}, {SOUTH, &get_south},
                        {EST, &get_est}, {WEST, &get_west}, {-1, NULL}};
    int tmp = 0;
    int i = 0;

    while (tab[i].way != -1) {
        if (tab[i].way == way) {
            tmp = tab[i].ptr(player_pos, layer1->width);
            break;
        }
        i++;
    }
    if ((tmp >= 0 && tmp <= layer1->height * layer1->width)
        && layer1->tiles[tmp] != 0)
        return (TRUE);
    return (FALSE);
}

int get_pos_in_tiles(sfVector2f pos, tiles_t *layer1)
{
    int tmp_x = 0;
    int tmp_y = 0;
    int nb_x = 0;
    int nb_y = 0;

    while (tmp_y != layer1->height && tmp_y < (int)pos.y) {
        tmp_y += layer1->tileSize.y;
        nb_y++;
    }
    while (tmp_x != layer1->width && tmp_x < (int)pos.x) {
        tmp_x += layer1->tileSize.x;
        nb_x++;
    }
    return (layer1->width * nb_y + nb_x);
}

void collision(game_t *gm)
{
    int p_pos = get_pos_in_tiles(gm->chara.pos, gm->tiles.collision);

    gm->colli.north = (is_in_collision(gm->tiles.collision, p_pos, NORTH) == TRUE) ?
                        TRUE : FALSE;
    gm->colli.south = (is_in_collision(gm->tiles.collision, p_pos, SOUTH) == TRUE) ?
                        TRUE : FALSE;
    gm->colli.est = (is_in_collision(gm->tiles.collision, p_pos, EST) == TRUE) ?
                        TRUE : FALSE;
    gm->colli.west = (is_in_collision(gm->tiles.collision, p_pos, WEST) == TRUE) ?
                        TRUE : FALSE;
}