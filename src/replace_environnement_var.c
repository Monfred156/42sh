/*
** EPITECH PROJECT, 2019
** replace_environnement_var
** File description:
** replace_environnement_var.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

char *get_var_env(char *var_env, char *string)
{
    char *final_var_env = recup_var(var_env);
    char *start_string = recup_start_string(string);
    char *result = NULL;

    result = my_strcat(start_string, final_var_env);
    return (result);
}

char *get_rank_var(char *string, char *var_name, data_t *data)
{
    char **env_array;
    int i = 0;

    for (; data->cpy_env[i]; i++) {
        env_array = my_str_to_word_array(data->cpy_env[i], "=");
        if (strcmp(env_array[0], var_name) == 0)
            break;
    }
    if (data->cpy_env[i] == NULL) {
        printf("%s: Undefined variable.\n", var_name);
        return ("\0");
    }
    return (get_var_env(data->cpy_env[i], string));
}

char *get_var_name(char *string, data_t *data)
{
    char *var_name = check_malloc_char(strlen(string) + 1);
    int n = 0;
    int i = 0;

    for (; string[i] != '$'; i++);
    for (i++; string[i] != '\0'; i++) {
        var_name[n] = string[i];
        n++;
    }
    var_name[n] = '\0';
    string = get_rank_var(string, var_name, data);
    return (string);
}

char **replace_env_change_array(char **array, int i, data_t *data, bool *detec)
{
    char **array_str;

    array_str = my_str_to_word_array(array[i], " ");
    for (int j = 0; array_str[j]; j++) {
        if (array_str[j][0] == '$')
            array[i] = get_var_name(array[i], data);
        if (array[i][0] == '\0')
            *detec = true;
    }
    my_free(array_str);
    return (array);
}

char **replace_environnement_var(char **array, data_t *data, bool *detec)
{
    for (int i = 0; array[i]; i++)
        array = replace_env_change_array(array, i, data, detec);
    return (array);
}