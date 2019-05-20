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
    char **array;

    while (1) {
        if (isatty(0))
            my_putstr("42sh> ");
        if (getline(&string, &len, stdin) == -1) {
            return 84;
        }
        string = space_in_str(string);
        array = my_str_to_word_array(string);
        for (int i = 0; array[i]; i++)
            printf("%s\n", array[i]);
    }
}