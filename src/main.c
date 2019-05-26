/*
** EPITECH PROJECT, 2018
** main
** File description:
** main.c
*/

#include "function.h"

int main(int ac, char **av, char **env)
{
    get_redir_double_left(av[1]);
    if (ac != 1)
        return (84);
    return (main_42sh(env));
}