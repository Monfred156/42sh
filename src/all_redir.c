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
#include "function.h"

char **get_redir_double_left(char *final)
{
    char **result = check_malloc_char_star(1);
    size_t len = 0;
    char *str = NULL;

    result[0] = NULL;
    for (int nb = 0; my_strcmp(final, str) != 0; nb++) {
        my_putstr("? ");
        if (getline(&str, &len, stdin) == -1)
            break;
        str = remove_n(str);
        result = my_realloc_array(result, 1);
        result[nb] = my_str_copy(str);
    }
    for (int nb = 0; result[nb] != NULL; nb++) {
        printf("%s\n", result[nb]);
    }
    return (result);
}

char *get_file_after_redir(char *string)
{
    int i = 0;
    char *str = malloc(sizeof(char) * strlen(string));
    int place = 0;

    for (; string[place] != '>' && string[place] != '<' &&
    string[place]; place++);
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



bool redir_left(char **array, int *inout, int i)
{
    int fd = 0;
    int continu = 0;
    char *file = get_file_after_redir(array[i]);

    if (array[i][1] == '<')

    fd = open(file, O_RDONLY);
    if (fd != -1)
        inout[0] = fd;
    else {
        inout[0] = 0;
        my_putstr_error(file);
        my_putstr_error(": No such file or directory.\n");
        continu = 1;
    }
    for (; array[i + 1]; i++)
        array[i] = array[i + 1];
    array[i] = NULL;
    if (continu == 1)
        return (false);
    else
        return (true);
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