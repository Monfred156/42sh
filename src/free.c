/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** ncauet
*/

#include <unistd.h>
#include <stdlib.h>

void free_char_double_star(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}