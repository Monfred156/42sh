/*
** EPITECH PROJECT, 2019
** recup_str
** File description:
** recup_str.c
*/

#include "function.h"

char *recup_var(char *var_env)
{
    char *string = malloc(sizeof(char) * (strlen(var_env) + 1));
    int i = 0;
    int n = 0;

    for (; var_env[i] != '='; i++);
    for (i++; var_env[i]; i++) {
        string[n] = var_env[i];
        n++;
    }
    string[n] = '\0';
    return (string);
}

char *recup_start_string(char *string)
{
    char *result = malloc(sizeof(char) * (strlen(string) + 1));
    int i = 0;

    for (; string[i] != '$'; i++)
        result[i] = string[i];
    result[i] = '\0';
    return (result);
}