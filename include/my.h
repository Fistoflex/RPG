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
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include "struct.h"
#include "link.h"
#include "enum.h"
#include "get_next_line.h"
#include "item.h"

int my_random(int max);
sfSprite   *insert_stuff(sfSprite *sp, char *str);
void my_putchar(char);
int my_putstr(char *);
int my_strlen(char *);
int my_putstr_error(char *);
char **my_str_to_word_array(char *, char);
char *my_strcat(char *, char *, int, int);
char *my_strdup(char *, int);
int my_strlen(char *);
int    my_strcmp(char *s1, char *s2);

char    *my_itoa(int nb);
void    save_game(game_t *gm);
char    *my_new_strcat(char *dest, char *src, int x, int fre);
void my_customize(sfRenderWindow *wind, game_t *gm, list_t **list, sfEvent *);
char    *get_next_line(int fd);
char **set_tab(char *path);
void    set_list(choice_t **elem, char **tab);
void    move_player(sfRenderWindow *wind, game_t *gm);
void	my_stuff(sfSprite *sp, sfVector2f pos, sfIntRect, sfRenderWindow *);
void	set_rect_stuff(sfRenderWindow *wind, game_t *gm, sfIntRect rect);
sfIntRect   my_create_rect(int h, int w, int t, int l);
int to_the_left(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
int to_the_right(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
int to_the_top(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
int to_the_bot(sfRenderWindow *wind, game_t *gm, sfIntRect *rect);
void    all_scene(sfRenderWindow *window, game_t *gm, list_t **, sfEvent *evt);
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
void my_game(sfRenderWindow *wind, game_t *gm);
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
void malloc_my_link_choice(choice_t **, sfSprite *, char *, char *);
void init_my_link_hp(heal_t **hp, sfVector2f pos);

list_t *press_down(sfRenderWindow *wind, game_t *gm, list_t *list);
list_t *press_up(sfRenderWindow *wind, game_t *gm, list_t *list);
choice_t *press_right(sfRenderWindow *wind, game_t *gm, choice_t *choice);
choice_t *press_left(sfRenderWindow *wind, game_t *gm, choice_t *choice);
list_t *init_my_custome(void);
list_t *make_your_choice(sfRenderWindow *wind, game_t *gm, list_t *list);
void save_my_choice(sfRenderWindow *wind, list_t *list, game_t *game);
char **read_file(char *path);
slot_t    set_one_slot(slot_t one, int i);
void    init_slot(slot_t *, slot_t *, slot_t *);
sfFont  *my_font(char *path);
char    *my_epurstr(char *str, char *format, int fre);
void    my_slot(sfRenderWindow *wind, game_t *gm);
char  *prompt(game_t *, sfEvent *);
void    the_free(char **tab);
void    destroy_bt(button_t bt);
sfView *set_view(sfView *, float zoom);

void keyboard_guide(sfRenderWindow *wind, game_t *gm);
int contain(sfRenderWindow *win, int pressed, game_t *gm, settings_t set);

void init_inventory(game_t *gm);
heal_t *init_normal_hp(int);
void draw_hp(sfRenderWindow *win, heal_t *hp);
void    redirec_out(char **tab, char *path);
void do_slash(sfRenderWindow *wind, game_t *gm, sfIntRect *rect, int);
void do_dash(sfRenderWindow *wind, game_t *gm, sfIntRect *rect, int);
void    my_inventory(sfRenderWindow *wind, game_t *gm);
sfRectangleShape *my_create_shape(sfVector2f size, sfVector2f, sfColor color);
statistics_t init_statistique(char *file);

text_t init_text(char **tab);
void create_link_bag(bag_t **bag, char *str, char **tp);
sfColor set_color(char **tab);
sfVector2f set_coord(char *str);
void init_inv_elem(game_t *gm);
char **all_path(void);
void draw_shape(bag_t *bag, sfRenderWindow *wind);
void disp_my_wp(sfSprite *, sfVector2f, sfIntRect, sfRenderWindow *);
bag_t *set_enum(bag_t *tmp);
void init_bag(game_t *gm);
void disp_bag(sfRenderWindow *wind, game_t *gm);
sfVector2f position(char *str);
void draw_txt(sfRenderWindow *wind, text_t txt);
int disp_elm(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f);
void disp_player(sfRenderWindow *wind, game_t *gm);
void elem_to_disp(sfRenderWindow *wind, bag_t **bag, sfSprite *sp, game_t *gm);
void disp_pl(sfRenderWindow *wind, sfSprite *sp, sfIntRect rect, sfVector2f);
void dis_elem(sfRenderWindow *wind, game_t *gm);

#endif
