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
    INTRO
};

enum button_t {
    STAR = 6,
    SETG,
    HOME,
    RESTAR,
    RESUME
};

enum button {
    PUSHED = 11,
    NOT_PUSHED
};

enum command {
    NEXT = 13,
    PREV
};

enum custom_step {
    CHOICE = 15,
    NAME
};

enum free_s {
    FREE = 17,
    KEEP
};

enum exit_t {
    EXIT = 84
};

#endif
