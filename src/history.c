/*
** EPITECH PROJECT, 2018
** history
** File description:
** .c
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "function.h"

int array_len(char **array)
{
    int counter = 0;
    for (; array[counter]; counter++);
    return (counter);
}

char **add_one_line_end_of_array(char **array, char *str)
{
    int i = 0;
    char **array_dup = malloc(sizeof(char *) * (array_len(array) + 2));
    for (; array[i]; i++)
        array_dup[i] = array[i];
    array_dup[i] = str;
    array_dup[i + 1] = NULL;
    return (array_dup);
}