/*
** EPITECH PROJECT, 2019
** add_chars_to_str
** File description:
** add_chars_to_str.c
*/

#include "../../include/my.h"

char *add_chars_to_str(char *str, char *characteres)
{
    str = my_realloc(str, my_strlen(characteres));
    for (int nb = 0; characteres[nb] != '\0'; nb++)
        str[my_strlen(str)] = characteres[nb];
    return (str);
}