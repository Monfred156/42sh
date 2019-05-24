/*
** EPITECH PROJECT, 2019
** cpy
** File description:
** array
*/

#include "function.h"
#include <stdlib.h>

char **cpy_array(char **array)
{
    char **array_dup;
    int counter = 0;
    for (; array[counter] != NULL; counter++);
    array_dup = malloc(sizeof(char *) * (counter + 2));
    for (int i = 0; array[i] != NULL; i++)
        array_dup[i] = array[i];
    array_dup[counter] = NULL;
    return (array_dup);
}
