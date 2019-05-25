/*
** EPITECH PROJECT, 2023
** PSU_42sh_2018
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include "struct.h"

char **initialisation_old_pwd(void)
{
    char **old_pwd;

    old_pwd = malloc(sizeof(char *) * 2);
    old_pwd[0] = NULL;
    old_pwd[1] = NULL;
    return (old_pwd);
}

void init_struct(data_t *data)
{
    data->finish = false;
    data->to_return = 0;
    data->old_pwd = initialisation_old_pwd();
}
