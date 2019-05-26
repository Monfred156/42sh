/*
** EPITECH PROJECT, 2019
** search_function
** File description:
** search_function.c
*/

#include <zconf.h>
#include <stdio.h>
#include "function.h"

int search_env_function(char **argv, data_t *data)
{
    if (my_strcmp(argv[0], "env") == 0)
        return (print_env(data->cpy_env));
    if (my_strcmp(argv[0], "setenv") == 0)
        return (check_setenv(argv, data));
    if (my_strcmp(argv[0], "unsetenv") == 0)
        return (check_unsetenv(argv, data));
    return (excve_function(argv, data));
}

int search_cd_and_exit_func(char **argv, data_t *data)
{
    if (my_strcmp(argv[0], "exit") == 0)
        return (check_exit(data, argv));
    if (my_strcmp(argv[0], "cd") == 0)
        return (check_cd(argv, data));
    if (my_strcmp(argv[0], "history") == 0)
        return (print_history(data->history));
    return (search_env_function(argv, data));
}

int search_builtin_function(char *str, data_t *data, int *inout_put)
{
    int cpy_in = dup(0);
    int cpy_out = dup(1);
    int value;
    char **argv = my_str_to_word_array(str, " ");

    dup2(inout_put[0], 0);
    dup2(inout_put[1], 1);

    if (my_strcmp(argv[0], "echo") == 0)
        value = echo_func(argv);
    else
        value = search_cd_and_exit_func(argv, data);
    dup2(cpy_in, 0);
    dup2(cpy_out, 1);
    return (value);
}