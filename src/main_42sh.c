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

int main_42sh(char **env)
{
    char *string = NULL;
    size_t len = 0;
    char **array;
    data_t data;

    get_env(env, &data);
    init_struct(&data);
    while (data.finish == false) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1)
            break;
        string = clean_reduce_str(string);
        if (check_error(string) == 0) {
            array = parse_string(string);
            get_str(array, &data);
        }
        string = NULL;
    }
    my_putstr("exit\n");
    return (data.to_return);
}