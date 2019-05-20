/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare 2 char *
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int nb;

    if (s1 == NULL || s2 == NULL)
        return (84);
    for (nb = 0; s1[nb] != 0 && s2[nb] != 0; nb++)
        if (s1[nb] != s2[nb])
            return (84);
    if (s1[nb] != 0)
        return (1);
    if (s2[nb] != 0)
        return (-1);
    return (0);
}