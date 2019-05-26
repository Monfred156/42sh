/*
** EPITECH PROJECT, 2019
** parse_string
** File description:
** parse_string.c
*/

#include <string.h>
#include <stdlib.h>
#include "function.h"

int malloc_nbr_string(char const *string)
{
    int counter = 0;

    for (int i = 0; string[i]; i++)
        if (string[i] == ' ')
            counter += 2;
    return (counter + 2);
}

int check_separator(char charca)
{
    if (charca == '|')
        return 1;
    if (charca == '&')
        return 1;
    if (charca == ';')
        return 1;
    return 0;
}

int malloc_same_array(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i + 1);
}

char **clean_array(char **array)
{
    char **result = check_malloc_char_star(malloc_same_array(array));
    int n = 0;
    int m = 0;

    for (int i = 0; array[i]; i++) {
        result[n] = check_malloc_char(strlen(array[i]) + 1);
        for (int j = 0; array[i][j]; j++) {
            if (array[i][0] != '\0') {
                result[n][m] = array[i][j];
                m++;
            }
        }
        result[n][m] = '\0';
        m = 0;
        if (array[i][0] != '\0')
            n++;
    }
    result[n] = NULL;
    free(array);
    return result;
}

char **parse_string(char *string)
{
    char **array = check_malloc_char_star(malloc_nbr_string(string) + 1);
    int *rank = check_malloc_int(2);

    rank[0] = 0;
    rank[1] = 0;
    array[rank[1]] = check_malloc_char(strlen(string) + 1);
    for (int i = 0; string[i]; i++) {
        if (string[i] == '>' || string[i] == '<')
            i = fill_array_after_redir(string, array, rank, i);
        else if (check_separator(string[i]) == 1)
            i = fill_array_after_separa(string, array, rank, i);
        else {
            array[rank[1]][rank[0]] = string[i];
            rank[0]++;
        }
    }
    array[rank[1]][rank[0]] = '\0';
    array[rank[1] + 1] = NULL;
    array = clean_array(array);
    return array;
}
