/*
** EPITECH PROJECT, 2019
** search_function
** File description:
** search_function.c
*/

#include "function.h"

int search_env_function(char **argv, data_t *data)
{
    if (my_strcmp(argv[0], "env") == 0) {
        print_env(data->cpy_env);
        return (VALID);
    }
    if (my_strcmp(argv[0], "setenv") == 0) {
        check_setenv(argv, data);
        return (0);
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        check_unsetenv(argv, data);
        return (0);
    }
    return (excve_function(argv, data));
}

int search_builtin_function(char *str, data_t *data, int *inout_put)
{
    int cpy_in = dup(0);
    int cpy_out = dup(1);
    int value = 0;
    char **argv = my_str_to_word_array(str, " ");

    dup2(inout_put[0], 0);
    dup2(inout_put[1], 1);
    if (my_strcmp(argv[0], "exit") == 0) {
        check_exit(data, argv);
        return (0);
    }
    if (my_strcmp(argv[0], "cd") == 0) {
        value = check_cd(argv, data);
        return (value);
    }
    value = search_env_function(argv, data);
    dup2(cpy_in, 0);
    dup2(cpy_out, 1);
    return (value);
}