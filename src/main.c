/*
** EPITECH PROJECT, 2018
** main
** File description:
** .c
*/

#include "function.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    return (main_42sh(env));
}