/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat.c
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *str1, char const *str2)
{
    int i = 0;
    int j = 0;
    char *dup = check_malloc_char(my_strlen(str1) + my_strlen(str2) + 1);

    for (; str1[i]; i++)
        dup[i] = str1[i];
    for (; str2[j]; j++)
        dup[i + j] = str2[j];
    dup[i + j] = '\0';
    return (dup);
}