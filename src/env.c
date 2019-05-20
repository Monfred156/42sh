/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** ncauet
*/

#include <unistd.h>
#include <stdlib.h>
#include <struct.h>
#include <string.h>

void free_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
}

int env_size(char **env)
{
    int count = 0;

    while (env[count] != NULL)
        count++;
    return (count);
}

int set_env(char **env, data_t *data)
{
    int x = 0;
    int y = 0;
    if (!(data->cpy_env = malloc(sizeof(char *) * (env_size(env) + 1))))
        return 1;

    while (env[x] != NULL) {
        if (!(data->cpy_env[x] = malloc(sizeof(char) * strlen(env[x]) + 1)))
            return (1);
        while (env[x][y] != '\0' && env[x][y] != '\n') {
            data->cpy_env[x][y] = env[x][y];
            y++;
        }
        data->cpy_env[x][y] = '\0';
        y = 0;
        x++;
    }
    data->cpy_env[x] = NULL;
    return (0);
}