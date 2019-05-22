/*
** EPITECH PROJECT, 2019
** all
** File description:
** redir.c
*/

#include "function.h"
#include <fcntl.h>

void redir_right(char **array, int *inout, int i)
{
    int fd = 0;

    if (array[i][1] != '>')
        fd = open(array[i + 1], O_CREAT | O_TRUNC | O_RDWR, 0664);
    else
        fd = open(array[i + 1], O_CREAT | O_APPEND | O_RDWR, 0664);
    for (; array[i + 2]; i++)
        array[i] = array[i + 2];
    array[i] = NULL;
    if (fd != -1)
        inout[1] = fd;
    else
        inout[1] = 1;
}

void redir_left(char **array, int *inout, int i)
{
    int fd = 0;

    fd = open(array[i + 1], O_RDONLY);
    if (fd != -1)
        inout[0] = fd;
    else {
        inout[0] = 0;
        my_putstr_error(array[i + 1]);
        my_putstr_error(": No such file or directory.");
        exit(0);
    }
    for (; array[i + 2]; i++)
        array[i] = array[i + 2];
    array[i] = NULL;
}

char *check_redir_and_path(char **array, char *path, int *inout, int i)
{
    inout[0] = 0;
    inout[1] = 1;
    if (array[i][0] == '<')
        redir_left(array, inout, i);
    if (array[i][0] == '>')
        redir_right(array, inout, i);
    dup2(inout[0], 0);
    dup2(inout[1], 1);
}