/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** exit
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "function.h"

int check_exit(data_t *data, char **array)
{
    if (array[1] != NULL) {
        if (my_str_isnum(array[1]) != 0) {
            write(2, "exit: Badly formed number.\n", 27);
            return (ERROR);
        }
        if (array[2] != NULL) {
            write(2, "exit: Expression Syntax.\n", 25);
            return (ERROR);
        }
        data->finish = true;
        data->to_return = atoi(array[1]);
    } else
        data->finish = true;
    return (VALID);
}