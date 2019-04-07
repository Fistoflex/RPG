/*
** EPITECH PROJECT, 2018
** m'enfiche
** File description:
** mon gars
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
