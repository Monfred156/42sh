/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

int main_42sh(char **env)
{
    char *string = NULL;
    size_t len = 0;
    char **array;
    data_t data;

    get_env(env, &data);
    while (1) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1)
            return 0;
        string = str_clean(string);
        string = remove_n(string);
        if (check_error(string) == 0) {
            array = parse_string(string);
            array = replace_environnement_var(array, &data);
            get_str(array, &data);
        }
        string = NULL;
    }
}