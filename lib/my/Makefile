##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile lib
##

SRC		=		create_link_list.c	\
				my_str_to_word_array.c	\
				my_strdup.c			\
				my_strlen.c			\
				rb_epurstr.c		\
				my_getnbr.c			\
				my_strcat.c			\
				my_strcmp.c			\
				word_array.c		\
				array_len.c			\
				getnbr.c			\
				isnum.c				\
				free_array.c		\
				my_putstr_error.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		=		-I../../include

NAME		=		libmy.a

all:				$(NAME)

$(NAME):			$(OBJ)
				ar rc $(NAME) $(OBJ)
				cp $(NAME) ../

clean:
				rm -f $(OBJ)

fclean:				clean
				rm -f $(NAME)
				rm -f ../$(NAME)

re:				fclean all
