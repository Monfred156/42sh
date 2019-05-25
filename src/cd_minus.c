/*
** EPITECH PROJECT, 2019
** cd
** File description:
** minus.c
*/

#include "function.h"

int recup_pwd(char **cpy_env)
{
    for (int i = 0; cpy_env[i] != NULL; i++) {
        if (cpy_env[i][0] == 'P' && cpy_env[i][1] == 'W' &&
            cpy_env[i][2] == 'D')
            return (i);
    }
    return (0);
}

char *recup_old_pwd(char **cpy_env)
{
    int j = 0;
    int counter = 0;
    char *old_pwd;

    for (int i = 0; cpy_env[i] != NULL; i++) {
        if (cpy_env[i][0] == 'P' && cpy_env[i][1] == 'W' &&
            cpy_env[i][2] == 'D') {
            old_pwd = malloc(sizeof(char) * my_strlen(cpy_env[i]));
            for (; cpy_env[i][counter] != '='; counter++);
            counter++;
            for (; cpy_env[i][counter]; counter++) {
                old_pwd[j] = cpy_env[i][counter];
                j++;
            }
            old_pwd[j] = '\0';
            return (old_pwd);
        }
    }
    return (NULL);
}

int algo_cd_firstb(data_t *data, int *count)
{
    int pwd = recup_pwd(data->cpy_env);
    char cwd[256];

    if (data->old_pwd[1] != NULL && chdir(data->old_pwd[1]) == -1) {
        my_putstr_error(data->old_pwd[1]);
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
        return (ERROR);
    } else {
        data->old_pwd[0] = recup_old_pwd(data->cpy_env);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            data->cpy_env[pwd] = my_strcat("PWD=", cwd);
    }
    return (VALID);
}

int algo_cd_firsta(data_t *data, int *count)
{
    int pwd = recup_pwd(data->cpy_env);
    char cwd[256];

    if (chdir(data->old_pwd[0]) == -1) {
        my_putstr_error(data->old_pwd[0]);
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
        return (ERROR);
    } else {
        data->old_pwd[1] = recup_old_pwd(data->cpy_env);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            data->cpy_env[pwd] = my_strcat("PWD=", cwd);
    }
    return (VALID);
}

int algo_cd_first(data_t *data, int *count)
{
    if (data->old_pwd[0] == NULL) {
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
        return (ERROR);
    } else {
        if (*count % 2 == 0) {
            if (algo_cd_firsta(data, count) == ERROR)
                return (ERROR);
        } else {
            if (algo_cd_firstb(data, count) == ERROR)
                return (ERROR);
        }
    }
    return (VALID);
}