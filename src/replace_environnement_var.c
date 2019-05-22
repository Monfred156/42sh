/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

char **replace_environnement_var(char **array, data_t *data)
{
    char **array_str;

    for (int i = 0; array[i];i++) {
        array_str = my_str_to_word_array(array[i], " ");
        for (int j = 0; array_str[j]; j++) {
            printf("%s\n", array_str[j]);
        }
    }
    return array;
}