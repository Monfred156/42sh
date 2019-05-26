/*
** EPITECH PROJECT, 2019
** my_count_array
** File description:
** compte le nombre de x charactère dans un char **
*/

#include <stdlib.h>

int my_count_char(char **str, char chrctr, int y, int x)
{
    if (str[y][x] == chrctr)
        return (1);
    return (0);
}

int my_count_array(char **str, char chrctr)
{
    int count = 0;

    for (int y = 0; str[y] != NULL; y++)
        for (int x = 0; str[y][x] != 0; x++)
            count += my_count_char(str, chrctr, y, x);
    return (count);
}