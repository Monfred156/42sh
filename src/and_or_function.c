/*
** EPITECH PROJECT, 2019
** and_or_function
** File description:
** and_or_function.c
*/

#include "function.h"

int and_function(char *str, char **env, int result)
{
    if (result == 0)
        return (search_builtin_function(str, env));
    return (0);
}

int or_function(char *str, char **env, int result)
{
    if (result == 1)
        return (search_builtin_function(str, env));
    return (0);
}