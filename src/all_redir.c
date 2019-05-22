/*
** EPITECH PROJECT, 2019
** all
** File description:
** redir.c
*/

#include "function.h"
#include <fcntl.h>

char *get_file_after_redir(char *string)
{
    int i = 0;
    char *str = malloc(sizeof(char) * strlen(string));
    int place = 0;

    for (; string[place] != '>' && string[place] != '<' && string[place]; place++);
    place++;
    if (string[place + 1] == '>' || string[place + 1] == '<')
        place++;
    place++;
    for (; string[place]; place++) {
        str[i] = string[place];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void redir_right(char **array, int *inout, int i)
{
    int fd = 0;
    char *file = get_file_after_redir(array[i]);

    if (array[i][1] != '>')
        fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0664);
    else
        fd = open(file, O_CREAT | O_APPEND | O_RDWR, 0664);
    for (; array[i + 1]; i++)
        array[i] = array[i + 1];
    array[i] = NULL;
    if (fd != -1)
        inout[1] = fd;
    else
        inout[1] = 1;
}

void redir_left(char **array, int *inout, int i)
{
    int fd = 0;
    char *file = get_file_after_redir(array[i]);

    fd = open(file, O_RDONLY);
    if (fd != -1)
        inout[0] = fd;
    else {
        inout[0] = 0;
        my_putstr_error(file);
        my_putstr_error(": No such file or directory.");
        exit(0);
    }
    for (; array[i + 1]; i++)
        array[i] = array[i + 1];
    array[i] = NULL;
}

void check_redir_and_path(char **array, int *inout, int i)
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