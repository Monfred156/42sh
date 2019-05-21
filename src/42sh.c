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
    int exit_value = 0;
    data_t *data = malloc(sizeof(data_t));

    get_env(env, data);
    while (1) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1)
            return 84;
        string = str_clean(string);
        printf("%s\n", string);
        string = remove_n(string);
        array = parse_string(string);
        if (check_exit_command_exist(array) == 0) {
            exit_value = check_exit_value(array);
            if (exit_value != -1)
                return (exit_value);
        }
        for (int i = 0; array[i]; i++)
           printf("%s\n", array[i]);
    }
}