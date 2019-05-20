/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include <stdlib.h>
#include "my.h"

char *del_to_much_space(char *str)
{
    char *copy = malloc(sizeof(char));
    int count = 1;

    if (copy == NULL)
        return (NULL);
    copy[0] = '\0';
    for (int nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] == ' ')
            count++;
        else
            count = 0;
        if (count <= 1) {
            copy = my_realloc(copy, 1);
            copy[my_strlen(copy)] = str[nb];
        }
    }
    free(str);
    if (copy[my_strlen(copy) - 1] == ' ')
        copy[my_strlen(copy) - 1] = '\0';
    return (copy);
}

char *str_simple_char(char *copy, char *str, int *nb)
{
    switch (str[*nb]) {
        case ';':
            copy = add_chars_to_str(copy, " ; ");
            break;
        case '|':
            copy = add_chars_to_str(copy, " | ");
            break;
        case '>':
            copy = add_chars_to_str(copy, " > ");
            break;
        case '<':
            copy = add_chars_to_str(copy, " < ");
            break;
        default:
            copy = my_realloc(copy, 1);
            copy[my_strlen(copy)] = str[*nb];
    }
    return (copy);
}

char *str_direction(char *copy, char *str, int *nb)
{
    if (str[*nb] == '>' && str[*nb + 1] == '>') {
        copy = add_chars_to_str(copy, " >> ");
        *nb += 1;
    } else if (str[*nb] == '<' && str[*nb + 1] == '<') {
        copy = add_chars_to_str(copy, " << ");
        *nb += 1;
    } else copy = str_simple_char(copy, str, nb);
    return (copy);
}

char *str_and_or(char *copy, char *str, int *nb)
{
    if (str[*nb] == '&' && str[*nb + 1] == '&') {
        copy = add_chars_to_str(copy, " && ");
        *nb += 1;
    } else if (str[*nb] == '|' && str[*nb + 1] == '|') {
        copy = add_chars_to_str(copy, " || ");
        *nb += 1;
    } else copy = str_direction(copy, str, nb);
    return (copy);
}

char *space_in_str(char *str)
{
    char *copy = malloc(sizeof(char));

    for (int nb = 0; str[nb] != '\0'; nb++)
        if (str[nb] == '\t')
            str[nb] = ' ';
    if (my_strlen(str) == 0)
        return (NULL);
    if (copy == NULL)
        exit (84);
    copy[0] = '\0';
    for (int nb = 0; str[nb] != '\0'; nb++)
        copy = str_and_or(copy, str, &nb);
    free(str);
    copy = del_to_much_space(copy);
    return (copy);
}