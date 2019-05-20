/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include <stdlib.h>
#include "my.h"

char *add_chars_to_str(char *str, char *characteres)
{
    str = my_realloc(str, my_strlen(characteres));
    for (int nb = 0; characteres[nb] != '\0'; nb++)
        str[my_strlen(str)] = characteres[nb];
    return (str);
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
    char *copy = malloc(sizeof(char) * 1);

    if (copy == NULL || my_strlen(str) == 0)
        return (NULL);
    copy[0] = '\0';
    for (int nb = 0; str[nb] != '\0'; nb++)
        copy = str_and_or(copy, str, &nb);
    free(str);
    return (copy);
}