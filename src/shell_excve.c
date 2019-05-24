/*
** EPITECH PROJECT, 2019
** shell_excve
** File description:
** shell_excve.c
*/

#include "function.h"

void print_command_not_found(char *str)
{
    my_putstr_error(str);
    my_putstr_error(": Command not found.\n");
}

void crash_file(int status)
{
    switch (WTERMSIG(status)) {
        case SIGSEGV:
            my_putstr_error("Segmentation fault");
            break;
        case SIGFPE:
            my_putstr_error("Floating exception");
            break;
        default:
            return;
    }
    if (WCOREDUMP(status))
        my_putstr_error(" (core dumped)");
    my_putstr_error("\n");
}

char *check_all_path(char **path, char *copy, char *str)
{
    copy = add_chars_before_str(copy, "/");
    copy = add_chars_before_str(copy, path[0]);
    for (int nb = 0; path[nb] != NULL &&
    access(copy, X_OK) != 0; nb++) {
        free(copy);
        copy = my_str_copy(str);
        copy = add_chars_before_str(copy, "/");
        copy = add_chars_before_str(copy, path[nb]);
    }
    if (access(copy, X_OK) != 0 || my_str_count(str, "/") > 0 ||
    my_str_count(str, ".") == 1) {
        free(copy);
        copy = my_str_copy(str);
    }
    return (copy);
}

char *access_path(char *str, data_t *data)
{
    char *copy = my_str_copy(str);
    char *env_path;
    char **path;
    int nb;

    for (nb = 0; data->cpy_env[nb] != NULL &&
    my_strcmp(data->cpy_env[nb], "PATH=") != 1; nb++);
    if (data->cpy_env[nb] != NULL) {
        env_path = check_malloc_char(my_strlen(data->cpy_env[nb]) - 4);
        for (int cpy = 5; data->cpy_env[nb][cpy - 1] != '\0'; cpy++)
            env_path[cpy - 5] = data->cpy_env[nb][cpy];
        path = my_str_to_word_array(env_path, ":");
        copy = check_all_path(path, copy, str);
        free(env_path);
        my_free(path);
    }
    return (copy);
}

int excve_function(char **argv, data_t *data)
{
    char *copy = access_path(argv[0], data);
    int pid;
    int status = 1;

    if (access(copy, X_OK) == 0) {
        pid = fork();
        if (pid < 0)
            exit (84);
        if (pid == 0)
            execve(copy, argv, data->cpy_env);
        else {
            waitpid(pid, &status, 0);
            crash_file(status);
        }
    } else
        print_command_not_found(argv[0]);
    if (status != 0)
        return (ERROR);
    return (VALID);
}