/*
** EPITECH PROJECT, 2019
** setenv
** File description:
** setenv.c
*/

#include <stdlib.h>
#include "function.h"

int error_setenv(char **array)
{
    if (array[1][0] <= 57 && array[1][0] >= 48) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 0; array[1][i]; i++)
        if (array[1][i] < 48 || (array[1][i] > 57 && array[1][i] < 65) ||
            (array[1][i] > 90 && array[1][i] < 97) || array[1][i] > 122) {
            my_putstr_error("setenv: Variable name must contain ");
            my_putstr_error("alphanumeric characters.\n");
            return (1);
        }
    return (0);
}

int check_arg(char **array, data_t *data, int count)
{
    int counter = 0;
    char *dup = NULL;

    for (int i = 0; data->cpy_env[i] != NULL; i++) {
        counter = 0;
        for (; data->cpy_env[i][counter] != '='; counter++);
        free(dup);
        dup = check_malloc_char(counter + 1);
        for (counter = 0; data->cpy_env[i][counter] != '='; counter++)
            dup[counter] = data->cpy_env[i][counter];
        dup[counter] = '\0';
        if (my_strcmp(array[count], dup) == 0)
            return (i);
    }
    return (-1);
}

char **not_here(char **cpy_env, char **array)
{
    char *path;
    char *path_second;
    char **other_cpy_env;

    other_cpy_env = cpy_array(cpy_env);
    if (array[2] != NULL) {
        path = my_strcat(array[1], "=");
        path_second = my_strcat(path, array[2]);
        other_cpy_env[array_len(cpy_env)] = path_second;
    } else {
        path = my_strcat(array[1], "=");
        other_cpy_env[array_len(cpy_env)] = path;
    }
    other_cpy_env[array_len(cpy_env) + 1] = NULL;
    return (other_cpy_env);
}

char **already_here(char **cpy_env, int i, char **array)
{
    char *path;

    if (array[2] != NULL) {
        path = my_strcat(array[1], "=");
        cpy_env[i] = my_strcat(path, array[2]);
    } else
        cpy_env[i] = my_strcat(array[1], "=");
    return (cpy_env);
}

int check_setenv(char **array, data_t *data)
{
    int check = 0;

    if (array_len(array) == 2 || array_len(array) == 3) {
        if (error_setenv(array) == 1)
            return (1);
        check = check_arg(array, data, 1);
        if (check == -1)
            data->cpy_env = not_here(data->cpy_env, array);
        else
            data->cpy_env = already_here(data->cpy_env, check, array);
    } else if (array_len(array) > 3)
        my_putstr_error("setenv: Too many arguments.\n");
    else
        print_env(data->cpy_env);
    return (0);
}