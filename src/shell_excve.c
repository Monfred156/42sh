/*
** EPITECH PROJECT, 2019
** shell_excve
** File description:
** shell_excve.c
*/

#include "function.h"

void check_all_path(char **path, char *copy, char *str)
{
    copy = add_chars_before_str(copy, "/");
    copy = add_chars_before_str(copy, path[0]);
    for (int nb = 0; path[nb] != NULL &&
    access(str, X_OK) != 0; nb++) {
        free(copy);
        copy = my_str_copy(str);
        copy = add_chars_before_str(copy, "/");
        copy = add_chars_before_str(copy, path[nb]);
    }
    if (access(copy, X_OK) != 0 || my_str_count(str, "/") > 0) {
        free(copy);
        copy = my_str_copy(str);
    }
}

char *access_path(char *str, char **env)
{
    char *copy = my_str_copy(str);
    char *env_path;
    char **path;
    int nb;

    for (nb = 0; env[nb] != NULL &&
    my_strcmp(env[nb], "PATH=") != 1; nb++);
    if (env[nb] != NULL) {
        env_path = check_malloc_char(my_strlen(env[nb]) - 4);
        for (int cpy = 5; env[nb][cpy - 1] != '\0'; cpy++)
            env_path[cpy - 5] = env[nb][cpy];
        path = my_str_to_word_array(env_path, ":");
        check_all_path(path, copy, str);
    }
    free(env_path);
    my_free(path);
    return (copy);
}

void excve_function(char *str, char **argv, char **env)
{
    char *copy = access_path(str, env);
    int pid;

    if (access(copy, X_OK) == 0) {
        pid = fork();
        if (pid < 0)
            exit (84);
        execve(copy, argv, env);
    } else {
        my_putstr_error(str);
        my_putstr_error(": Command not found.\n");
    }
}