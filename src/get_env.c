/*
** EPITECH PROJECT, 2019
** get_env
** File description:
** get_env.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <struct.h>
#include <string.h>
#include "function.h"

void free_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
}

void get_env(char **env, data_t *data)
{
    int x = 0;
    int y = 0;

    data->cpy_env = check_malloc_char_star(array_len(env) + 1);
    while (env[x] != NULL) {
        data->cpy_env[x] = check_malloc_char(my_strlen(env[x]) + 1);
        while (env[x][y] != '\0' && env[x][y] != '\n') {
            data->cpy_env[x][y] = env[x][y];
            y++;
        }
        data->cpy_env[x][y] = '\0';
        y = 0;
        x++;
    }
    data->cpy_env[x] = NULL;
}
