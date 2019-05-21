/*
** EPITECH PROJECT, 2018
** my_putstr2.c
** File description:
** print un char * en erreur
*/

#include "my.h"
#include <unistd.h>

void my_put_error(char const *str)
{
    write (2, str, my_strlen(str));
}
