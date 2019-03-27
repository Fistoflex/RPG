/*
** EPITECH PROJECT, 2019
** video_mode
** File description:
** video_mode
*/

#include "my.h"

sfVideoMode set_videomode(void)
{
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    return (video_mode);
}