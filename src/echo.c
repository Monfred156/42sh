/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo.c
*/

#include <stdlib.h>
#include "function.h"

void delete_char(char *str, int nb)
{
    for (; str[nb] != 0; nb++)
        str[nb] = str[nb + 1];
}

int check_quote(char *str, char quote, int *nb)
{
    delete_char(str, *nb);
    for (; str[*nb] != '\0' && str[*nb] != quote; *nb += 1);
    if (str[*nb] != quote && quote == '\'') {
        my_putstr_error("Unmatched '''.\n");
        return (ERROR);
    }
    if (str[*nb] != quote && quote == '\"') {
        my_putstr_error("Unmatched '\"'.\n");
        return (ERROR);
    }
    delete_char(str, *nb);
    *nb -= 1;
    return (VALID);
}

int if_char_quote(char *str, int *nb)
{
    if (str[*nb] == '\'') {
        if (check_quote(str, '\'', nb) == ERROR)
            return (ERROR);
    } else if (str[*nb] == '\"')
        if (check_quote(str, '\"', nb) == ERROR)
            return (ERROR);
    return (VALID);
}

int delete_quote(char **argv)
{
    int nb1;
    int nb2;
    int result = VALID;

    for (nb1 = 1; result == VALID && argv[nb1] != NULL; nb1++)
        for (nb2 = 0; result == VALID && argv[nb1][nb2] != '\0'; nb2++)
            result = if_char_quote(argv[nb1], &nb2);
    return (result);
}

int echo_func(char **argv)
{
    int nb = 1;

    if (delete_quote(argv) == ERROR) 
        return (ERROR);
    if (my_strcmp(argv[1], "-n") == 0)
        nb++;
    for (; argv[nb] != NULL; nb++) {
        my_putstr(argv[nb]);
        if (argv[nb + 1] != NULL)
            my_putchar(' ');
    }
    if (my_strcmp(argv[1], "-n") != 0)
        my_putchar('\n');
    return (VALID);
}