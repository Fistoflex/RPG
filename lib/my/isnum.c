/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** do_the_str_isnum
*/

int isnum(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
