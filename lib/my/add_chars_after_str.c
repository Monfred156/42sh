/*
** EPITECH PROJECT, 2019
** add_chars_to_str
** File description:
** add_chars_to_str.c
*/

#include "my.h"

char *add_chars_after_str(char *str, char *add)
{
    str = my_realloc(str, my_strlen(add));
    for (int nb = 0; add[nb] != '\0'; nb++)
        str[my_strlen(str)] = add[nb];
    return (str);
}