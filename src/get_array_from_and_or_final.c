/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

bool check_redir_until_end_or_pipe(char **array, int *nb, int *inout_put)
{
    bool exec = true;
    for (int i = *nb; array[i] && array[i][0] != '|'; i++) {
        if (array[i][0] == '<' || array[i][0] == '>') {
            exec = check_redir_and_path(array, inout_put, i);
            *nb -= 1;
        }
    }
    return (exec);
}

int get_array_from_and_or_final(data_t *data, char **array)
{
    bool exec = true;
    int value = 0;
    int inout_put[2] = {0, 1};
    for (int i = 0; array[i]; i++) {
        exec = check_redir_until_end_or_pipe(array, &i, inout_put);
        if (exec == false)
            break;
        if (i > 0) {
            if (array[i - 1][0] == '|' && array[i + 1] != NULL &&
            array[i + 1][0] == '|')
                middle_pipe(inout_put, array);
            if (array[i - 1][0] == '|' &&
            (array[i + 1] == NULL || array[i + 1][0] != '|'))
                last_pipe(inout_put, array);
            if (array[i - 1][0] != '|' && array[i + 1][0] == '|')
                first_pipe(inout_put, array);
        }
        if (i >= 0)
            value = search_builtin_function(array[i], data->cpy_env, inout_put);
    }
    return (value);
}