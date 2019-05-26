/*
** EPITECH PROJECT, 2019
** fill_array_pars
** File description:
** fill_array_pars.c
*/

#include <stdlib.h>
#include <string.h>
#include "function.h"

int fill_array_after_separa(const char *string, char **array, int *rank, int i)
{
    array[rank[1]][rank[0]] = '\0';
    array[rank[1] + 1] = check_malloc_char(3);
    rank[0] = 0;
    for (; string[i] != '\0' && string[i] != ' '; i++) {
        array[rank[1] + 1][rank[0]] = string[i];
        rank[0]++;
    }
    array[rank[1] + 1][rank[0]] = '\0';
    rank[1] += 2;
    array[rank[1]] = check_malloc_char(strlen(string) + 1);
    rank[0] = 0;
    return i;
}

int fill_array_after_redir(const char *string, char **array, int *rank, int i)
{
    array[rank[1]][rank[0]] = '\0';
    rank[1]++;
    array[rank[1]] = check_malloc_char(strlen(string) + 1);
    rank[0] = 0;
    for (; string[i] != '\0' && string[i] != ' '; i++) {
        array[rank[1]][rank[0]] = string[i];
        rank[0]++;
    }
    array[rank[1]][rank[0]] = ' ';
    rank[0]++;
    i++;
    for (; string[i] != '\0' && string[i] != ' '; i++) {
        array[rank[1]][rank[0]] = string[i];
        rank[0]++;
    }
    array[rank[1]][rank[0]] = '\0';
    rank[1]++;
    array[rank[1]] = check_malloc_char(strlen(string) + 1);
    rank[0] = 0;
    return i;
}
