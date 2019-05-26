/*
** EPITECH PROJECT, 2019
** redir
** File description:
** left.c
*/

#include "function.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **get_redir_double_left(char *final)
{
    char **result = check_malloc_char_star(1);
    size_t len = 0;
    char *str = NULL;
    int nb;

    result[0] = NULL;
    for (nb = 0; my_strcmp(final, str) != 0; nb++) {
        my_putstr("? ");
        free(str);
        str = NULL;
        if (getline(&str, &len, stdin) == -1)
            break;
        result = my_realloc_array(result, 1);
        result[nb] = my_str_copy(str);
        str = remove_n(str);
    }
    if (nb > 0)
        free(result[nb - 1]);
    result[nb - 1] = NULL;
    return (result);
}

void redir_double_left(char **array, int *inout, int i, char *str)
{
    char **double_redir = get_redir_double_left(str);
    int cpy_out = dup(1);
    int fdpipe[2] = {0, 1};

    if (pipe(fdpipe) != -1) {
        dup2(fdpipe[1], 1);
        for (int j = 0; double_redir[j]; j++)
            my_putstr(double_redir[j]);
        close(fdpipe[1]);
        inout[0] = fdpipe[0];
        dup2(cpy_out, 1);
    }
}

int simple_redir_left(char *file, int *inout)
{
    int fd;
    int continu = 0;

    fd = open(file, O_RDONLY);
    if (fd != -1)
        inout[0] = fd;
    else {
        inout[0] = 0;
        my_putstr_error(file);
        my_putstr_error(": No such file or directory.\n");
        continu = 1;
    }
    return (continu);
}

bool redir_left(char **array, int *inout, int i)
{
    int continu = 0;
    char *file = get_file_after_redir(array[i]);

    if (array[i][1] == '<')
        redir_double_left(array, inout, i, file);
    else
        continu = simple_redir_left(file, inout);
    for (; array[i + 1]; i++)
        array[i] = array[i + 1];
    array[i] = NULL;
    if (continu == 1)
        return (false);
    return (true);
}