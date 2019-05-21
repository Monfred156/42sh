/*
** EPITECH PROJECT, 2019
** search_function
** File description:
** search_function.c
*/

#include "function.h"

int search_env_function(char **argv, char **env)
{
    if (my_strcmp(argv[0], "env") == 0)
        return(0);
    if (my_strcmp(argv[0], "setenv") == 0)
        return(0);
    if (my_strcmp(argv[0], "unsetenv") == 0)
        return(0);
    return (excve_function(argv, env));
}

int search_builtin_function(char *str, char **env)
{
    char **argv = my_str_to_word_array(str, " ");

    if (my_strcmp(argv[0], "exit") == 0)
        return(0);
    if (my_strcmp(argv[0], "cd") == 0)
        return(0);
    return (search_env_function(argv, env));
}