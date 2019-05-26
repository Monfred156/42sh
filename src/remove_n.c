/*
** EPITECH PROJECT, 2019
** remove_n
** File description:
** remove_n.c
*/

#include "function.h"

char *remove_n(char *string)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == '\n')
            string[i] = '\0';
    return (string);
}