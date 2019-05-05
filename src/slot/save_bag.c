/*
** EPITECH PROJECT, 2019
** save
** File description:
** save
*/

#include "my.h"

char *type_of_coord(int state)
{
    if (state == HEAD)
        return ("0");
    if (state == TORSO)
        return ("1");
    if (state == PANTS)
        return ("2");
    if (state == FEET)
        return ("3");
    if (state == WP)
        return ("4");
    if (state == HAND)
        return ("5");
    return (NULL);
}

char *set_str(bag_t *bag)
{
    char *str = my_strcat(my_itoa(bag->state), " ", KEEP, KEEP);
    char *ptr = set_text_to_save(bag->itm.txt);

    ptr = my_epurstr(ptr, "\n", FREE);
    for (int i = 0; ptr[i] != '\0'; i++)
        if (ptr[i] == ' ')
            ptr[i] = ',';
    str = my_strcat(str, bag->itm.path, FREE, KEEP);
    str = my_strcat(str, " ", FREE, KEEP);
    str = my_strcat(str, ptr, FREE, FREE);
    str = my_strcat(str, " ", FREE, KEEP);
    ptr = NULL;
    ptr = type_of_coord(bag->state);
    if (ptr == NULL)
        return (my_strdup("none", KEEP));
    str = my_strcat(str, ptr, KEEP, KEEP);
    return (str);
}

void set_first_line(bag_t *bag, char *path, int state)
{
    int fd = 0;
    char *str = NULL;

    if (state == 1) {
        str = set_str(bag);
        str = my_strcat(str, "\n", FREE, KEEP);
        fd = open(path, O_WRONLY | O_TRUNC);
        write(fd, str, my_strlen(str));
    } else {
        fd = open(path, O_WRONLY | O_APPEND);
        while (bag != NULL) {
            str = set_str(bag);
            str = my_strcat(str, "\n", FREE, KEEP);
            write(fd, str, my_strlen(str));
            free(str);
            bag = bag->next;
        }
    }
    close(fd);
}

void save_bag(game_t *gm)
{
    bag_t *bag = gm->chara.bag.bag;
    int i = 0;
    char *path = my_strcat(gm->chara.path.slot, "bag", KEEP, KEEP);

    while (i != 15) {
        i++;
        bag = bag->next;
    }
    set_first_line(bag, path, 1);
    set_first_line(bag, path, 2);
}