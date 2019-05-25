/*
** EPITECH PROJECT, 2019
** env
** File description:
** env.c
*/

#include "function.h"

void print_env(char **cpy_env)
{
    for (int i = 0; cpy_env[i] != NULL; i++) {
        my_putstr(cpy_env[i]);
        my_putchar('\n');
    }
}