/*
** EPITECH PROJECT, 2019
** check_malloc
** File description:
** check_malloc.c
*/

#include <stdlib.h>

char *check_malloc_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    if (str == NULL)
        exit(84);
    return (str);
}

char **check_malloc_char_star(int size)
{
    char **array = malloc(sizeof(char *) * size);

    if (array == NULL)
        exit(84);
    return (array);
}

int *check_malloc_int(int size)
{
    int *array = malloc(sizeof(int *) * size);

    if (array == NULL)
        exit(84);
    return (array);
}