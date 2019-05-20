/*
** EPITECH PROJECT, 2018
** history
** File description:
** .c
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "function.h"

char **add_one_line_end_of_array(char **array, char *str)
{
    int i = 0;
    char **array_dup = malloc(sizeof(char *) * (array_len(array) + 2));

    for (; array[i]; i++)
        array_dup[i] = array[i];
    array_dup[i] = str;
    array_dup[i + 1] = NULL;
    free(array);
    return (array_dup);
}

void print_history(char **history)
{
    int counter = 0;
    int counter_max = 0;

    for (int nb_max = array_len(history) - 1; nb_max > 0; nb_max /= 10)
        counter_max++;
    for (int i = 0; history[i]; i++) {
        counter = 0;
        for (int dup = i; dup > 0; dup /= 10)
            counter++;
        if (i == 0)
            counter++;
        for (; counter < counter_max; counter++)
            my_putchar(' ');
        my_putchar(' ');
        my_put_nbr(i);
        my_putstr("  ");
        my_putstr(history[i]);
        my_putchar('\n');
    }
}