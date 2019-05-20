/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "my.h"
#include "function.h"

char *remove_n(char *string)
{
    for (int i = 0; string[i]; i++) {
        if (string[i] == '\n')
            string[i] = '\0';
    }
    return string;
}

