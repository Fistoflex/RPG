/*
** EPITECH PROJECT, 2019
** character
** File description:
** character
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

typedef struct char_s {
    sfVector2f pos;
    sfSprite *body;
    sfSprite *hair;
    sfSprite *hat;
    sfSprite *torso;
    sfSprite *shoulder;
    sfSprite *hands;
    sfSprite *legs;
    sfSprite *feet;
}chara_t;

#endif 
