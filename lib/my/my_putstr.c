/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
