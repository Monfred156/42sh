/*
** EPITECH PROJECT, 2019
** my_strsub_char
** File description:
** delete x charactere of the char *
*/

#include "function.h"
#include <stdlib.h>

char *my_strsub_char(char *str, char *chrctr)
{
    int count = my_str_count(str, chrctr);
    char *copy = check_malloc_char(my_strlen(str) + 1 - count);
    int nb2 = 0;

    for (int nb = 0; str[nb] != 0; nb++)
        if (str[nb] != chrctr[0]) {
            copy[nb2] = str[nb];
            nb2++;
        }
    copy[nb2] = 0;
    free(str);
    return (copy);
}