/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo.c
*/

#include <stdlib.h>
#include "function.h"

int echo_func(char **argv)
{
    int nb = 1;

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