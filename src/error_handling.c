/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include <string.h>
#include <errno.h>
#include "function.h"

int ambigous_redirect(char **array, int i)
{
    if ((strcmp(array[i], "|") == 0 || strcmp(array[i], "<") == 0 ||
    strcmp(array[i], "<<") == 0) && array[i + 1] != NULL &&
    array[i+2] != NULL && (strcmp(array[i + 2], "<") == 0 ||
    strcmp (array[i + 2], "<<") == 0)) {
        my_putstr("Ambiguous input redirect.\n");
        return (1);
    }
    if ((strcmp(array[i], ">") == 0 || strcmp(array[i], ">>") == 0) &&
    array[i + 1] != NULL && array[i+2] != NULL &&
    (strcmp(array[i + 2], "|") == 0 || (strcmp(array[i+2], ">>") == 0 ||
    strcmp(array[i+2], ">") == 0))) {
        my_putstr("Ambiguous output redirect.\n");
        return (1);
    }
    return (0);
}

int check_invalid_command(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (string_is_redir(array[i]) == 0 &&
        string_is_separator(array[i+1]) == 0) {
            my_putstr("Missing name for redirect.\n");
            return (1);
        }
        if ((string_is_separator(array[i]) == 0 &&
        string_is_separator(array[i+1]) == 0) ||
        (i == 0 && string_is_sep_no_redir(array[i]) == 0)) {
            my_putstr("Invalid null command.\n");
            return (1);
        }
        if (ambigous_redirect(array, i) == 1)
            return (1);
    }
    return (0);
}

int check_error(char *string)
{
    char **array = create_argv(string);
    if (check_invalid_command(array) == 1)
        return (1);
    return (0);
}

void display_execve_error(char *cmd)
{
    if (errno == ENOEXEC) {
        my_putstr_error(cmd);
        my_putstr_error(": Exec format error. Wrong Architecture\n");
    }
}