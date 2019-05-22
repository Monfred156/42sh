/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <stdlib.h>
#include "function.h"

int count_str_left(char **tab, int act_cpt)
{
    int nbr = 0;

    while (tab[act_cpt] && strcmp(tab[act_cpt], "&&") != 0 &&
        strcmp(tab[act_cpt], "||") != 0 &&
        strcmp(tab[act_cpt], ";") != 0) {
        nbr++;
        act_cpt++;
    }
    return (nbr);
}

char **get_next_tab(int *i, char **cmd_parsed)
{
    int cpt = 0;
    char **tab = malloc(sizeof(char *) * (count_str_left(cmd_parsed, *i) + 1));

    while (cmd_parsed[(*i)] && strcmp(cmd_parsed[(*i)], "&&") != 0 &&
        strcmp(cmd_parsed[(*i)], "||") != 0 &&
        strcmp(cmd_parsed[(*i)], ";") != 0) {
        tab[cpt] = strdup(cmd_parsed[(*i)]);
        (*i)++;
        cpt++;
    }
    tab[cpt] = NULL;
    return (tab);
}

void get_str(char **cmd_parsed, data_t *data)
{
    char **my_tab = NULL;

    for (int i = 0; cmd_parsed[i]; i++) {
        my_tab = get_next_tab(&i, cmd_parsed);
        get_array_from_and_or_final(data, my_tab);
        my_free(my_tab);
        if (!cmd_parsed[i])
            return;
    }
}