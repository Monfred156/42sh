/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

char **replace_environnement_var(char **array, data_t *data)
{
    for (int i = 0; array[i];i++) {
        for (int j = 0; array[i][j]; j++) {
            if (array[i][j] == '$')
        }
    }
    return array;
}