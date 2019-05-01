##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

SRC		=			src/key/key/bt_esc_redirect.c   \
					src/key/key/find_the_bt_which_is_press.c \
					src/key/mouse/get_mouse_pos.c	\
					src/all_scene/all_scene.c	\
					src/intro/my_intro.c		\
					src/manage_event/main_event.c	\
					src/game/my_game.c		\
					src/game/move_player/to_the_left.c	\
					src/game/move_player/to_the_right.c	\
					src/game/move_player/to_the_top.c	\
					src/game/move_player/to_the_bot.c	\
					src/game/move_player/all_cond_moves.c	\
					src/menu/my_menu.c		\
					src/menu/init_the_scn_menu.c	\
					src/menu/color_txt_menu.c	\
					src/pause/my_pause.c		\
					src/pause/button_pause_effect.c	\
					src/pause/init_the_scn_pause.c	\
					src/setting/init_the_scene_settings.c   \
					src/setting/my_setting.c	\
					src/is_open.c			\
					src/video_mode.c		\
					src/create_text.c		\
					src/my_create_sprite.c		\
					src/my_clock.c			\
					src/biggest_txt.c		\
					src/init_the_button_rectangle.c	\
					src/init_struct_game.c		\
					src/my_create_rect.c		\
					src/all_scene/customer_sc/prompt.c		\
					src/customize/customer_scene.c			\
					src/customize/my_chose.c	\
					src/set_tab.c			\
					src/customize/set_elem.c	\
					src/customize/save_my_choice.c	\
					src/get_next_line.c			\
					src/customize/init_my_custome.c		\
					src/customize/my_customize.c		\
					src/setting/contain.c	\
					src/setting/keyboard_guide.c	\
					src/read_file.c				\
					src/my_new_strcat.c			\
					src/slot/my_slot.c			\
					src/slot/init_slot.c			\
					src/slot/save_game.c			\
					src/my_itoa.c					\
					src/inventory/init_inventory.c	\
					src/inventory/my_inventory.c	\
					src/tiled/get_tiles.c			\
					src/tiled/load_map.c			\
					src/tiled/make_map.c			\
					src/inventory/init_my_text.c	\
					src/inventory/create_link_bag.c	\
					src/inventory/annex_inventory.c	\
					src/my_random.c					\
					src/game/fight/draw_hp.c		\
					src/game/fight/init_hp.c		\
					src/game/fight/fight.c			\
					src/game/move_player/do_spell.c	\
					src/my_create_shape.c			\
					src/init_statistique_slot.c		\
					src/tiled/collision.c			\
					src/tiled/get_way.c

MAIN		=			src/main.c

SRC_TEST	=		tests/test_create_link_list.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		my_rpg

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-I./include -g -lm -g3 -g -ggdb

LIB		=		-L./lib -lmy

GRAPH		=		-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

LDFLAGS		=		-lcriterion --coverage

all:				run

run:			$(OBJ)
				make -sC lib/my
				$(CC) -o $(NAME) $(OBJ) $(LIB) $(GRAPH)

tests_run:
				make -sC lib/my
		$(CC) -o $(BIN) $(SRC) $(SRC_TEST) $(CFLAGS) $(LIB) $(LDFLAGS)
				./$(BIN)

clean:
			make -sC lib/my clean
			rm -f $(OBJ)
			rm -f *.gc*

fclean:			clean
			make -sC lib/my fclean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all
