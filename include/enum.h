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
    GUI,
    HOME,
    RESTAR,
    RESUME
};

enum button {
    PUSHED = 12,
    NOT_PUSHED
};

enum command {
    NEXT = 14,
    PREV
};

enum custom_step {
    CHOICE = 16,
    NAME
};

enum exit_t {
    EXIT = 84
};

#endif
