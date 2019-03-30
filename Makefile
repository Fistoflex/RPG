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
					src/game/my_game.c	\
					src/menu/my_menu.c	\
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
					src/init_struct_game.c

MAIN		=			src/main.c

SRC_TEST	=		tests/test_create_link_list.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		my_rpg

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-I./include -g

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
