/*
** EPITECH PROJECT, 2019
** str_to
** File description:
** word_array
*/

#include "../../include/my.h"
#include <stdlib.h>

int spaces(char *str)
{
    int counter_spaces = 0;
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if ((str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0' &&
        str[i + 1] != '\t')) || (str[i] == '\t' &&
        (str[i + 1] != ' ' && str[i + 1] != '\0' && str[i + 1] != '\t')))
            counter_spaces++;
    }
    return (counter_spaces);
}

char **check_null(char **all)
{
    all = malloc(sizeof(char *) * 2);
    all[0] = '\0';
    all[1] = NULL;
    return (all);
}

char *get_dup(char *str, int *i, char *dup)
{
    int counter_malloc = 0;
    for (int j = *i; str[j] != ' ' && str[j] != '\0' && str[j] != '\t'; j++)
        counter_malloc++;
    dup = malloc(sizeof(char) * (counter_malloc + 1));
    for (int j = 0; str[*i] != ' ' && str[*i] != '\0' &&
    str[*i] != '\t'; j++) {
        dup[j] = str[*i];
        *i += 1;
    }
    dup[counter_malloc] = '\0';
    return (dup);
}

char **my_str_to_word_array(char *str)
{
    int counter_str = 0;
    char *dup;
    char **all = malloc(sizeof(char *) * (spaces(str) + 2));
    if (spaces(str) == 0 &&
        (str[0] == ' ' || str[0] == '\0' || str[0] == '\t')) {
        char **all = check_null(all);
        return (all);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        dup = get_dup(str, &i, dup);
        if (dup != NULL && dup[0] != '\0') {
            all[counter_str] = dup;
            counter_str++;
        }
    }
    all[counter_str] = NULL;
    return (all);
}