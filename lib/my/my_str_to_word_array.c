/*
** EPITECH PROJECT, 2019
** my_str_up
** File description:
** transforme un char * en char **
*/

#include <stdlib.h>
#include "my.h"

int search_in_character(char *map, char *character, int where)
{
    for (int nb = 0; character[nb] != 0; nb++)
        if (map[where] == character[nb])
            return (1);
    return (0);
}

void fill_str(char **result, char *map, char *character)
{
    int count = 0;
    int nb_2 = 0;
    int size = my_strlen(map) - 1;

    for (int nb = 0; map[nb] != 0; nb++) {
        if (search_in_character(map, character, nb) == 0) {
            result[count][nb_2] = map[nb];
            nb_2++;
        } else {
            result[count][nb_2] = 0;
            count++;
            nb_2 = 0;
        }
    }
    if (map[0] == 0)
        size = 0;
    if (search_in_character(map, character, size) == 0)
        result[count][nb_2] = 0;
    else
        result[count] = NULL;
}

void malloc_str(char **result, char *map, char *character)
{
    int save;
    int nb = -1;
    int sub = 0;

    for (save = 0; map[save] != 0; save++) {
        for (nb++; map[save] != 0 &&
        search_in_character(map, character, save) == 0; save++);
        result[nb] = malloc(sizeof(char) * (save - sub + 1));
        sub = save + 1;
        if (map[save] == 0)
            save--;
    }
    if (save == 0)
        result[0] = malloc(sizeof(char));
}

char **my_to_word_array(char *map, char *character)
{
    char **result;
    int count = 1;

    for (int nb = 0; map[nb] != 0; nb++)
        if (search_in_character(map, character, nb) == 1)
            count++;
    result = malloc(sizeof(char *) * (count + 1));
    result[count] = NULL;
    malloc_str(result, map, character);
    fill_str(result, map, character);
    return (result);
}