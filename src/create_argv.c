/*
** EPITECH PROJECT, 2019
** create_argv
** File description:
** create_argv.c
*/

#include <stdlib.h>
#include "function.h"

int search_param(char *str)
{
    if (my_strcmp(str, ";") == 0 ||
    my_strcmp(str, "|") == 0 ||
    my_strcmp(str, "<") == 0 ||
    my_strcmp(str, ">") == 0 ||
    my_strcmp(str, "<<") == 0 ||
    my_strcmp(str, ">>") == 0 ||
    my_strcmp(str, "||") == 0 ||
    my_strcmp(str, "&&") == 0)
        return (1);
    return (0);
}

void delete_line(char **str, int nb)
{
    for (; str[nb] != NULL; nb++) {
        free(str[nb]);
        str[nb] = my_str_copy(str[nb + 1]);
    }
}

char **create_argv(char *str)
{
    char **result;

    result = my_str_to_word_array(str, " ");
    for (int nb = 0; result[nb] != NULL &&
    result[nb + 1] != NULL; nb++)
        if (search_param(result[nb]) == 0 &&
        search_param(result[nb + 1]) == 0) {
            result[nb] = add_chars_after_str(result[nb], " ");
            result[nb] = add_chars_after_str(result[nb], result[nb + 1]);
            delete_line(result, nb + 1);
            nb--;
        }
    return (result);
}