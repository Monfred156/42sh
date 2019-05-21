/*
** EPITECH PROJECT, 2019
** my_str_copy
** File description:
** copy un char *
*/

#include <stdlib.h>
#include "my.h"

char *my_str_copy(char *str)
{
    char *copy;
    int count;

    if (str == NULL)
        return (NULL);
    for (count = 0; str[count] != 0; count++);
    copy = check_malloc_char(count + 1);
    for (int nb = 0; nb <= count; nb++)
        copy[nb] = str[nb];
    return (copy);
}
