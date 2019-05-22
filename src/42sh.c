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
    char *cpy_string;

    get_env(env, &data);
    while (1) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1)
            return 84;
        cpy_string = str_clean(string);
        cpy_string = remove_n(cpy_string);
        if (check_error(cpy_string) == 0) {
            array = parse_string(cpy_string);
            //array = replace_environnement_var(array, &data);
            for (int i = 0; array[i]; i++)
                printf("%s\n", array[i]);
        }
    }
}