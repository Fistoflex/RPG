/*
** EPITECH PROJECT, 2019
** init_my_custom
** File description:
** init_my_custome
*/

#include "my.h"

void init_one_two(choice_t **one, choice_t **two,
char **tab_one, char **tab_two)
{
    set_list(one, tab_one);
    set_list(two, tab_two);
}

list_t *init_my_custome(void)
{
    list_t *list = NULL;
    char **tab_hair = set_tab("config/character/hair");
    char **tab_pants = set_tab("config/character/pants");
    char **tab_body = set_tab("config/character/body");
    char **tab_feet = set_tab("config/character/feet");
    char **tab_t_shirts = set_tab("config/character/t_shirts");
    choice_t *body = NULL;
    choice_t *hair = NULL;
    choice_t *feet = NULL;
    choice_t *t_shirts = NULL;
    choice_t *pants = NULL;

    init_one_two(&body, &hair, tab_body, tab_hair);
    init_one_two(&feet, &pants, tab_feet, tab_pants);
    set_list(&t_shirts, tab_t_shirts);
    malloc_my_link_list(&list, hair);
    malloc_my_link_list(&list, body);
    malloc_my_link_list(&list, t_shirts);
    malloc_my_link_list(&list, pants);
    malloc_my_link_list(&list, feet);
    return (list);
}