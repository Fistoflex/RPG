##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile lib
##

SRC		=		create_link_list.c		\
				my_putchar.c			\
				my_putstr.c				\
				my_putstr_error.c		\
				my_str_to_word_array.c	\
				my_strcat.c				\
				my_strdup.c				\
				my_strlen.c				\
				my_strdup.c

OBJ		=		$(SRC:.c=.o)

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
