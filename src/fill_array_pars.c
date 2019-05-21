/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "function.h"

int fill_array_after_separa(const char *string, char **array, int *rank, int i)
{
    array[rank[1]][rank[0]] = '\0';
    array[rank[1] + 1] = malloc(sizeof(char) * (3));
    rank[0] = 0;
    for (; string[i] != '\0' && string[i] != ' '; i++) {
        array[rank[1] + 1][rank[0]] = string[i];
        rank[0]++;
    }
    array[rank[1] + 1][rank[0]] = '\0';
    rank[1] += 2;
    array[rank[1]] = malloc(sizeof(char) * (strlen(string) + 1));
    rank[0] = 0;
    return i;
}

int fill_array_after_redir(const char *string, char **array, int *rank, int i)
{
    array[rank[1]][rank[0]] = '\0';
    rank[1]++;
    array[rank[1]] = malloc(sizeof(char) * (strlen(string) + 1));
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
    array[rank[1]] = malloc(sizeof(char) * (strlen(string) + 1));
    rank[0] = 0;
    return i;
}
