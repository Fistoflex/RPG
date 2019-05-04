/*
** EPITECH PROJECT, 2019
** enum.h
** File description:
** enum.h
*/

#ifndef ENUM_H_
#define ENUM_H_

enum {
    TRUE = 0,
    FALSE
};

enum is_game {
    MENU = 2,
    PAUSE,
    GAME,
    INTRO,
    SLOT,
    INV
};

enum button_t {
    STAR = 8,
    SETG,
    GUI,
    HOME,
    RESTAR,
    RESUME
};

enum button {
    PUSHED = 13,
    NOT_PUSHED
};

enum command {
    NEXT = 15,
    PREV
};

enum custom_step {
    CHOICE = 17,
    NAME
};

enum free_s {
    FREE = 19,
    KEEP
};

enum item_s {
    HEAD = 21,
    TORSO,
    PANTS,
    FEET,
    WP,
    HAND,
    SUPP,
    NONE,
    IMN
};

enum exit_t {
    EXIT = 84
};

enum clean_s {
    REPLACE = 200,
    SKIP,
    SPACE
};

enum ways {
    NORTH = 1,
    SOUTH,
    EST,
    WEST
};

#endif
