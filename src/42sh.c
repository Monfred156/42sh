/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "my.h"
#include "function.h"

int main_42sh(void)
{
    char *string = NULL;
    size_t len = 0;

    while (1) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1) {
            return 84;
        }
    }
}