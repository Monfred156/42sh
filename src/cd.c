/*
** EPITECH PROJECT, 2019
** cd
** File description:
** cd.c
*/

#include "function.h"

char *recup_home(char **cpy_env)
{
    int j = 0;
    int counter = 0;
    char *home;

    for (int i = 0; cpy_env[i] != NULL; i++) {
        if (cpy_env[i][0] == 'H' && cpy_env[i][1] == 'O' &&
            cpy_env[i][2] == 'M' && cpy_env[i][3] == 'E') {
            home = malloc(sizeof(char) * my_strlen(cpy_env[i]));
            for (; cpy_env[i][counter] != '='; counter++);
            counter++;
            for (; cpy_env[i][counter]; counter++) {
                home[j] = cpy_env[i][counter];
                j++;
            }
            home[j] = '\0';
            return (home);
        }
    }
    return (NULL);
}

void error_global_cd(struct stat filestat, char **array)
{
    if ((S_IFMT & filestat.st_mode) != S_IFDIR) {
        my_putstr_error(array[1]);
        my_putstr_error(": Not a directory.\n");
    } else if (filestat.st_mode | S_IXUSR) {
        my_putstr_error(array[1]);
        my_putstr_error(": Permission denied.\n");
    }
}

void only_cd(data_t *data, int count)
{
    char cwd[256];
    int pwd = recup_pwd(data->cpy_env);

    chdir(recup_home(data->cpy_env));
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        data->cpy_env[pwd] = my_strcat("PWD=", cwd);
    if (count % 2 == 0)
        data->old_pwd[0] = recup_old_pwd(data->cpy_env);
    else
        data->old_pwd[1] = recup_old_pwd(data->cpy_env);
}

int global_cd(char **array, data_t *data, int *count)
{
    struct stat filestat;
    char cwd[256];
    int pwd = recup_pwd(data->cpy_env);

    if (chdir(array[1]) != -1) {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            data->cpy_env[pwd] = my_strcat("PWD=", cwd);
        if (*count % 2 == 0)
            data->old_pwd[0] = recup_old_pwd(data->cpy_env);
        else
            data->old_pwd[1] = recup_old_pwd(data->cpy_env);
    } else if (stat(array[1], &filestat) != -1) {
        error_global_cd(filestat, array);
        *count -= 1;
        return (ERROR);
    } else {
        my_putstr_error(array[1]);
        my_putstr_error(": No such file or directory.\n");
        *count -= 1;
        return (ERROR);
    }
    return (VALID);
}

int check_cd(char **array, data_t *data)
{
    char cwd[256];
    static int count = 0;
    int value = 0;

    getcwd(cwd, sizeof(cwd));
    if (data->old_pwd[0] == NULL)
        data->old_pwd[1] = recup_old_pwd(data->cpy_env);
    if (array_len(array) == 1)
        only_cd(data, count);
    else {
        if (my_strcmp(array[1], "-") == 0)
            value = algo_cd_first(data, &count);
        else if (my_strcmp(array[1], "--") == 0 ||
                 my_strcmp(array[1], "~") == 0)
            only_cd(data, count);
        else
            value = global_cd(array, data, &count);
    }
    count++;
    return (value);
}