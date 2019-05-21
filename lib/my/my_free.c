/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** free un char **
*/

#include <stdlib.h>

void my_free(char **str)
{
    for (int nb = 0; str[nb] != NULL; nb++)
        free(str[nb]);
    free(str);
}