/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

char *get_var_name(char *string)
{
    char *tmp = malloc(sizeof(char) * (strlen(string) + 1));
    char *result;
    int n = 0;

    for (int i = 1; string[i] != '\0'; i++) {
        tmp[n] = string[i];
        n++;
    }
    tmp[n] = '\0';
    //result
}

char **replace_environnement_var(char **array, data_t *data)
{
    char **array_str;

    for (int i = 0; array[i];i++) {
        array_str = my_str_to_word_array(array[i], " ");
        for (int j = 0; array_str[j]; j++) {
            if (array_str[j][0] == '$')
                array[i] = get_var_name(array[i]);
        }
    }
    return array;
}