/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** count the characters in a string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return 0;
	else {
		while (str[i] != '\0') {
			i += 1;
		}
		return (i);
	}
}
