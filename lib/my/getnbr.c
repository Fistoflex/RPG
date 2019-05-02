/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/

int isnum(char *);

int getnbr(char *str)
{
    int i = 0;
    int return_value = 0;
    int state = 1;

    if (isnum(str) == 0)
        return (0);
    if (str[i] == '-') {
        i++;
        state = -1;
    }
    while (str[i] != '\0')
        return_value = return_value * 10 + (str[i++] - '0');
    return (return_value * state);
}
