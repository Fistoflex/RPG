/*
** EPITECH PROJECT, 2019
** init pause
** File description:
** pause
*/

#include "my.h"

button_t set_button(char *str, int x, int y, int size)
{
    button_t tmp;
    sfFont *font = sfFont_createFromFile("font/a.ttf");

    tmp.pos.x = x;
    tmp.pos.y = y;
    tmp.size = size;
    if (font == NULL)
        exit(84);
    tmp.txt = create_txt(str, font, size, tmp.pos);
    return (tmp);
}

pause_t init_the_scene_pause(void)
{
    pause_t pause;

    pause.resume = set_button("RESUME", 450, 200, 66);
    pause.home = set_button("HOME", 450, 400, 66);
    pause.restart = set_button("RESTART", 450, 600, 66);
    pause.exit = set_button("EXIT", 450, 800, 66);
    return (pause);
}
