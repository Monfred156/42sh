/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** realloc un char *
*/

#include <stdlib.h>

char *my_realloc(char *string, int nb)
{
    char *copy;
    int count;

    for (count = 0; string[count] != 0; count++);
    copy = malloc(sizeof(char) * (count + nb + 1));
    if (copy == NULL)
        exit (84);
    for (count = 0; string[count] != 0; count++)
        copy[count] = string[count];
    for (int i = count; i < nb + count + 1; i++)
        copy[i] = 0;
    free(string);
    return (copy);
}