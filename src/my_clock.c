/*
** EPITECH PROJECT, 2018
** my_clock
** File description:
** set clock
*/

#include "my.h"

float   my_clock(sfClock *clock)
{
    sfTime  time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}
