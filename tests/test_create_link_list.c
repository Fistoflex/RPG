/*
** EPITECH PROJECT, 2019
** tests my create_link_list
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(add_link, correct_list)
{
    int n = 0;
    choice_t *choix = NULL;
    char *av[] = {"premier", "second", NULL};

    while (av[n] != NULL) {
        malloc_my_link_list(&choix, NULL, av[n]);
        n++;
    }
    n = 0;
    while (choix->state_link != TRUE) {
        cr_assert_eq(av[n], choix->str);
        choix = choix->next;
        n++;
    }
}