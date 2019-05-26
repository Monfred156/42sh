/*
** EPITECH PROJECT, 2019
** all_redir
** File description:
** all_redir.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include "function.h"

char *get_file_after_redir(char *string)
{
    int i = 0;
    char *str = check_malloc_char(strlen(string));
    int place = 0;

    for (; string[place] != '>' && string[place] != '<' &&
    string[place]; place++);
    place++;
    if (string[place] == '>' || string[place] == '<')
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

bool check_redir_and_path(char **array, int *inout, int i)
{
    if (array[i][0] == '<') {
        if (redir_left(array, inout, i) == false)
            return (false);
    } else if (array[i][0] == '>')
        redir_right(array, inout, i);
    return (true);
}