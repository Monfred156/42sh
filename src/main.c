/*
** EPITECH PROJECT, 2018
** main
** File description:
** .c
*/

#include "function.h"

int main(int ac, char **av, char **env)
{
    char **a;

    a = create_argv(av[1]);
    for (int nb = 0; a[nb] != NULL; nb++) {
        my_putstr(a[nb]);
        my_putstr("\n");
    }
    //return (main_42sh(env));
}