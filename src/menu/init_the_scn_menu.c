/*
** EPITECH PROJECT, 2019
** init_the_scene_menu
** File description:
** init_the_scn_menu
*/

#include "my.h"

menu_t init_the_scene_menu(void)
{
    menu_t menu;

    menu.start = set_button("START", 250, 150, 66);
    menu.setg = set_button("SETTINGS", 250, 350, 66);
    menu.exit = set_button("EXIT", 250, 550, 66);
    return (menu);
}
