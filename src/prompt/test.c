/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <stddef.h>

char *add_char(char *, char);

int main(void)
{
    char *testo = "Ceci est un testo";
    char *testi = "";
    char *testa = NULL;

    testo = add_char(testo, 't');
    printf("[%s]\n", testo);
    testi = add_char(testi, 'o');
    printf("[%s]\n", testi);
    testa = add_char(testa, '5');
    printf("[%s]\n", testa);
}