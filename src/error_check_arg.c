/*
** EPITECH PROJECT, 2019
** error_check_string
** File description:
** error_check_string.c
*/

#include <string.h>
#include "function.h"

int string_is_redir(char *string)
{
    if (strcmp(string, ">>") == 0)
        return (0);
    if (strcmp(string, ">") == 0)
        return (0);
    if (strcmp(string, "<<") == 0)
        return (0);
    if (strcmp(string, "<") == 0)
        return (0);
    return (1);
}

int string_is_sep_no_redir(char *string)
{
    if (string == NULL)
        return (0);
    if (strcmp(string, "|") == 0)
        return (0);
    if (strcmp(string, "||") == 0)
        return (0);
    return (1);
}

int string_is_separator(char *string)
{
    if (string_is_sep_no_redir(string) == 0)
        return (0);
    if (strcmp(string, ">") == 0 || strcmp(string, ">>") == 0)
        return (0);
    if (strcmp(string, "&&") == 0)
        return (0);
    return (1);
}