/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <stdlib.h>
#include "function.h"

char **get_next_tab(int *i, char **cmd_parsed)
{
    char **tab = malloc(sizeof(char *) * 30);
    int cpt = 0;

    while (cmd_parsed[(*i)] && my_strcmp(cmd_parsed[(*i)], "&&") == 84 &&
            (my_strcmp(cmd_parsed[(*i)], "||") == 84 || my_strcmp(cmd_parsed[(*i)], "||") == -1) &&
        my_strcmp(cmd_parsed[(*i)], ";") == 84) {
        tab[cpt] = my_strdup(cmd_parsed[(*i)]);
        (*i)++;
        cpt++;
    }
    tab[cpt] = NULL;
    return (tab);
}

void get_str(char **cmd_parsed, data_t *data)
{
    char **my_tab = NULL;
    int operand = 0;

    for (int i = 0; cmd_parsed[i]; i++) {
        my_tab = get_next_tab(&i, cmd_parsed);
        get_array_from_and_or_final(data, my_tab);
        my_free(my_tab);
        if (!cmd_parsed[i])
            return;
    }
}