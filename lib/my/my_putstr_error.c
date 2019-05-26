/*
** EPITECH PROJECT, 2018
** my_putstr_error
** File description:
** my_putstr_error.c
*/

#include <unistd.h>
#include "my.h"

void my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
}
