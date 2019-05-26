/*
** EPITECH PROJECT, 2023
** init
** File description:
** init.c
*/

#include <stdlib.h>
#include "function.h"

char **initialisation_old_pwd(void)
{
    char **old_pwd;

    old_pwd = check_malloc_char_star(2);
    old_pwd[0] = NULL;
    old_pwd[1] = NULL;
    return (old_pwd);
}

void init_struct(data_t *data)
{
    data->finish = false;
    data->to_return = 0;
    data->old_pwd = initialisation_old_pwd();
    data->history = check_malloc_char_star(1);
    data->history[0] = NULL;
}