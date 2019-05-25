/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parser_and_or_semicolumn
*/

#include <stdlib.h>
#include "function.h"

int count_str_left(char **tab, int act_cpt)
{
    int nbr = 0;

    while (tab[act_cpt] && strcmp(tab[act_cpt], "&&") != 0 &&
        strcmp(tab[act_cpt], "||") != 0 && strcmp(tab[act_cpt], ";") != 0) {
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

void move_to_next_operand(int result, char **tab, int *i)
{
    if (tab[(*i)] && strcmp(tab[(*i)], "&&") == 0) {
        if (result == VALID)
            return;
        (*i)++;
        while (strcmp(tab[(*i)], "||") == 1 || strcmp(tab[(*i)], ";") == 1)
            (*i)++;
        return;
    } else if (tab[(*i)] && strcmp(tab[(*i)], "||") == 0) {
        (*i)++;
        if (result == VALID) {
            while (tab[(*i)] && strcmp(tab[(*i)], ";") == 1)
                (*i)++;
            return;
        }
        while (tab[(*i)] && strcmp(tab[(*i)], "||") == 1 &&
            strcmp(tab[(*i)], ";") == 1)
            (*i)++;
        return;
    }
}

void get_str(char **cmd_parsed, data_t *data)
{
    bool detect = false;
    char **my_tab = NULL;
    int result = -1;

    for (int i = 0; cmd_parsed[i]; i++) {
        my_tab = get_next_tab(&i, cmd_parsed);
        my_tab = replace_environnement_var(my_tab, data, &detect);
        if (detect == true)
            cmd_parsed[i + 1] = NULL;
        result = get_array_from_and_or_final(data, my_tab);
        move_to_next_operand(result, cmd_parsed, &i);
        if (!cmd_parsed[i])
            return;
    }
}