/*
** EPITECH PROJECT, 2019
** add_chars_before_str
** File description:
** ajoute n charactere devant un char *
*/

#include "my.h"

char *add_chars_before_str(char *str, char *add)
{
    int size = my_strlen(str);

    str = my_realloc(str, my_strlen(add));
    for (int nb = size; nb >= 0; nb--)
        str[nb + my_strlen(add)] = str[nb];
    for (int nb = 0; add[nb] != 0; nb++)
        str[nb] = add[nb];
    return (str);
}