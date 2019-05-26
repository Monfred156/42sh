/*
** EPITECH PROJECT, 2019
** main_42sh
** File description:
** main_42sh.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"

char *clean_reduce_str(char *string)
{
    string = str_clean(string);
    string = remove_n(string);
    return (string);
}

char *take_arg(char *string)
{
    size_t len = 0;

    free(string);
    string = NULL;
    if (isatty(0))
        my_putstr("42sh> ");
    if (getline(&string, &len, stdin) == -1)
        return (NULL);
    return (string);
}

int main_42sh(char **env)
{
    char *string = NULL;
    char **array;
    data_t data;

    get_env(env, &data);
    init_struct(&data);
    while (data.finish == false) {
        string = take_arg(string);
        if (string == NULL)
            break;
        data.history = add_one_line_end_of_array(data.history,
        my_strdup(string));
        string = clean_reduce_str(string);
        if (check_error(string) == 0) {
            array = parse_string(string);
            get_str(array, &data);
        }
    }
    my_putstr("exit\n");
    return (data.to_return);
}