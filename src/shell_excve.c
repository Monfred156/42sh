/*
** EPITECH PROJECT, 2019
** shell_excve
** File description:
** shell_excve.c
*/

#include "function.h"

void crash_file(int status, int pid)
{
    waitpid(pid, &status, 0);
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
    detect_exec(str) == 1) {
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

int search_file(char *str)
{
    struct stat file_stat;

    if (detect_exec(str) == 0)
        return (VALID);
    if (stat(str, &file_stat) == -1)
        return (VALID);
    if ((S_IFMT & file_stat.st_mode) != S_IFREG) {
        print_error_exec(str, ": Permission denied.\n");
        return (ERROR);
    }
    return (VALID);
}

int excve_function(char **argv, data_t *data)
{
    char *copy = access_path(argv[0], data);
    int pid;
    int status = 1;

    if (search_file(argv[0]) == ERROR)
        return (ERROR);
    if (access(copy, X_OK) == 0) {
        pid = fork();
        if (pid < 0)
            exit(84);
        if (pid == 0) {
            execve(copy, argv, data->cpy_env);
            exit(0);
        } else
            crash_file(status, pid);
    } else
        print_error_exec(argv[0], ": Command not found.\n");
    if (status != 0)
        return (ERROR);
    return (VALID);
}