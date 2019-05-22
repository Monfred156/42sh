/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

int get_array_from_and_or_final(data_t *data, char **array)
{
    int value = 0;
    int inout_put[2] = {0, 1};
    for (int i = 0; array[i]; i++) {
        if (array[i + 1] != NULL && (array[i + 1][0] == '>' || array[i + 1][0] == '<')) {
            check_redir_and_path(array, inout_put, i + 1);
            i--;
        } else {
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
            value = search_builtin_function(array[i], data->cpy_env, inout_put);
        }
    }
    return (value);
}