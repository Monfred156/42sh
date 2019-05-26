/*
** EPITECH PROJECT, 2019
** get_array_from_and_or_final
** File description:
** get_array_from_and_or_final.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <zconf.h>
#include <sys/wait.h>
#include "function.h"

bool check_redir_until_end_or_pipe(char **array, int *nb, int *inout_put, int *fd)
{
    bool exec = true;

    for (int i = *nb; array[i] && array[i][0] != '|'; i++) {
        if (array[i][0] == '<' || array[i][0] == '>') {
            exec = check_redir_and_path(array, inout_put, i, fd);
            if (i == *nb)
                *nb -= 1;
        }
    }
    return (exec);
}

bool check_pipe(char **array, int *inout_put, int i, int *pipefd)
{
    if (i > 0 && array[i - 1][0] == '|' && array[i + 1] != NULL &&
    array[i + 1][0] == '|') {
        middle_pipe(inout_put, pipefd);
        return true;
    }
    if (i > 0 && array[i - 1][0] == '|' &&
    (array[i + 1] == NULL || array[i + 1][0] != '|')) {
        last_pipe(inout_put, pipefd);
        return true;
    }
    if (((i > 0 && array[i - 1][0] != '|') || i == 0) && array[i+1] != NULL &&
    array[i + 1][0] == '|') {
        first_pipe(inout_put, pipefd);
        return true;
    }
    return false;
}

int get_array_from_and_or_final(data_t *data, char **array)
{
    bool exec = true;
    bool pipe = false;
    int value = 0;
    int inout_put[2] = {0, 1};
    int pipefd[2] = {0, 1};
    int fd[2] = {0, 1};

    for (int i = 0; array[i]; i++) {
        exec = check_redir_until_end_or_pipe(array, &i, inout_put, fd);
        if (exec == false)
            break;
        pipe = check_pipe(array, inout_put, i, pipefd);
        if (i >= 0)
            value = search_builtin_function(array[i], data, inout_put);
        if (pipe == true)
            i++;
        pipe = false;
    }
    return (value);
}