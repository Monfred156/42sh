/*
** EPITECH PROJECT, 2019
** my_realloc_array
** File description:
** realloc un char **
*/

#include <stdlib.h>
#include "my.h"

char **my_realloc_array(char **str, int nb)
{
    char **copy;
    int y = array_len(str);
    int x;

    copy = check_malloc_char_star(y + nb + 1);
    for (y = 0; str[y] != NULL; y++) {
        for (x = 0; str[y][x] != 0; x++) {}
        copy[y] = check_malloc_char(x + 1);
        for (x = 0; str[y][x] != 0; x++)
            copy[y][x] = str[y][x];
        copy[y][x] = 0;
    }
    for (int count = 0; count < nb + 1; count++)
        copy[y + count] = NULL;
    my_free(str);
    return (copy);
}
