/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

int string_is_separator(char *string)
{
    if (string == NULL)
        return 0;
    if (strcmp(string, "|") == 0)
        return 0;
    if (strcmp(string, "||") == 0)
        return 0;
    if (strcmp(string, ">>") == 0)
        return 0;
    if (strcmp(string, ">") == 0)
        return 0;
    if (strcmp(string, "<<") == 0)
        return 0;
    if (strcmp(string, "<") == 0)
        return 0;
    if (strcmp(string, "&&") == 0)
        return 0;
    if (strcmp(string, ";") == 0)
        return 0;
    return 1;
}

int string_is_redir(char *string)
{
    if (strcmp(string, ">>") == 0)
        return 0;
    if (strcmp(string, ">") == 0)
        return 0;
    if (strcmp(string, "<<") == 0)
        return 0;
    if (strcmp(string, "<") == 0)
        return 0;
    return 1;
}

int check_invalid_command(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (string_is_redir(array[i]) == 0 && string_is_separator(array[i+1])
        == 0) {
            my_putstr("Missing name for redirect.\n");
            return 1;
        }
        if (string_is_separator(array[i]) == 0 && string_is_separator
        (array[i+1]) == 0) {
            my_putstr("Invalid null command.\n");
            return 1;
        }
        if (string_is_redir(array[i]) == 0 && i == 0) {
            my_putstr("Invalid null command.\n");
            return 1;
        }
        if (strcmp(array[i], "|") == 0 && array[i + 1] != NULL && (strcmp
        (array[i + 2], "<") == 0 || strcmp(array[i + 2], "<<") == 0)) {
            my_putstr("Ambiguous input redirect.\n");
            return 1;
        }
        if ((strcmp(array[i], ">") == 0 || strcmp(array[i], ">>")) &&
        array[i+1] != NULL && strcmp(array[i+2], "|") == 0) {
            my_putstr("Ambiguous output redirect.\n");
            return 1;
        }
    }
    return 0;
}

int check_error(char *string)
{
    char **array = my_str_to_word_array(string, " ");
    /*for (int i = 0; array[i]; i++)
        printf("%s\n", array[i]);*/
    if (check_invalid_command(array) == 1)
        return 1;
    return 0;
}
