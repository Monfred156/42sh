/*
** EPITECH PROJECT, 2019
** cd
** File description:
** minus.c
*/

#include "include/my.h"

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

char **algo_cd_firstb(char **old_pwd, char **cpy_env, int *count)
{
    int pwd = recup_pwd(cpy_env);
    char cwd[256];

    if (old_pwd[1] != NULL && chdir(old_pwd[1]) == -1) {
        my_putstr_error(old_pwd[1]);
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
    } else {
        old_pwd[0] = recup_old_pwd(cpy_env);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            cpy_env[pwd] = my_strcat("PWD=", cwd);
    }
    return (old_pwd);
}

char **algo_cd_firsta(char **old_pwd, char **cpy_env, int *count)
{
    int pwd = recup_pwd(cpy_env);
    char cwd[256];

    if (chdir(old_pwd[0]) == -1) {
        my_putstr_error(old_pwd[0]);
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
    } else {
        old_pwd[1] = recup_old_pwd(cpy_env);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            cpy_env[pwd] = my_strcat("PWD=", cwd);
    }
    return (old_pwd);
}

char **algo_cd_first(char **old_pwd, char **cpy_env, int *count)
{
    if (old_pwd[0] == NULL) {
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
    } else {
        if (*count % 2 == 0)
            old_pwd = algo_cd_firsta(old_pwd, cpy_env, count);
        else {
            old_pwd = algo_cd_firstb(old_pwd, cpy_env, count);
        }
    }
    return (old_pwd);
}