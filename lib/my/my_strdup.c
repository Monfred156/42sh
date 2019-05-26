/*
** EPITECH PROJECT, 2019
** my_str_dup
** File description:
** my_str_dup.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *dup = check_malloc_char(size + 1);

    for (int i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[size] = '\0';
    return (dup);
}