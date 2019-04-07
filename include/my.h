/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Audio.h>
#include "struct.h"
#include "link.h"
#include "enum.h"
#include "get_next_line.h"


void my_putchar(char);
int my_putstr(char *);
int my_strlen(char *);
int my_putstr_error(char *);
char **my_str_to_word_array(char *, char);
char *my_strcat(char *, char *);
char *my_strdup(char *);

void prompt(sfRenderWindow *win, game_t *gm, sfEvent event);
char    *get_next_line(int fd);
char **set_tab(char *path);
void    set_list(choice_t **elem, char **tab);
void    move_player(sfRenderWindow *wind, game_t *gm);
void	my_stuff(sfSprite *sp, sfVector2f pos, sfIntRect rect, sfRenderWindow *wind);
void	set_rect_stuff(sfRenderWindow *wind, game_t *gm, sfIntRect rect);
sfIntRect   my_create_rect(int h, int w, int t, int l);
void	to_the_left(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
void    to_the_right(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
void    to_the_top(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
void    to_the_bot(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
void    all_scene(sfRenderWindow *window, game_t *gm, list_t **list);
void manage_event(sfRenderWindow *window, sfEvent evt, game_t *gm);
void my_intro(sfRenderWindow *wind, game_t *gm);
void resume_effect(game_t *gm);
void home_effect(game_t *gm);
void exit_effect(game_t *gm);
void restart_effect(game_t *gm);
int my_set_song(int sound, game_t *gm);
game_t init_struct_game(sfRenderWindow *window, sfVideoMode video_mode);
int my_set_the_new_scene(int push, game_t *gm, int stat);
sfVideoMode set_videomode(void);
void is_open(sfRenderWindow *, game_t, list_t *);
void my_menu(sfRenderWindow *, game_t *);
game_t set_game_elements(void);
void destroy_game_elements(game_t);
void set_menu_background(game_t *);
sfIntRect set_rectangle(void);
void my_pause(sfRenderWindow *wind, game_t *gm);
menu_t init_the_scene_menu(void);
void color_txt_start(game_t *);
void color_txt_exit(game_t *);
void color_txt_setg(game_t *);
void biggest_txt(button_t *, float, float);
pause_t init_the_scene_pause(void);
button_t set_button(char *str, int x, int y, int size);
sfText *create_txt(char *name, sfFont *font, int size, sfVector2f position);
void get_mouse_pos(game_t *gm, sfEvent evt);
void find_the_bt_which_is_press(game_t *gm, sfEvent evt);
void bt_esc_redirect(game_t *gm);
sfSprite *my_create_sprite(char *name, sfBool);
void my_game(sfRenderWindow *wind, game_t *gm, list_t **list);
void my_setting(sfRenderWindow *wind, game_t *gm);
float my_clock(sfClock *clock);
void my_setting(sfRenderWindow *, game_t *);
settings_t init_the_scene_settings(void);
sfIntRect init_the_button_rectangle(int, int, int, int);
sfVector2f set_shape_size(int, int);
sfVector2f set_shape_position(int, int);
void clic_menu_exit(sfRenderWindow *, game_t *, sfVector2i);
void clic_menu_settings(game_t *, sfVector2i);

void malloc_my_link_list(list_t **env, choice_t *choice);
void malloc_my_link_choice(choice_t **env, sfSprite *iteme, char *str);

list_t *press_down(sfRenderWindow *wind, game_t *gm, list_t *list);
list_t *press_up(sfRenderWindow *wind, game_t *gm, list_t *list);
choice_t *press_right(sfRenderWindow *wind, game_t *gm, choice_t *choice);
choice_t *press_left(sfRenderWindow *wind, game_t *gm, choice_t *choice);
list_t *init_my_custome(void);
list_t *make_your_choice(sfRenderWindow *wind, game_t *gm, list_t *list);
void save_my_choice(sfRenderWindow *wind, list_t *list, game_t *game);

char *add_char(char *, char);
char *remove_char(char *);

#endif
