/*
** EPITECH PROJECT, 2018
** array_len
** File description:
** array_len.c
*/

int array_len(char **array)
{
    int counter = 0;

    for (; array[counter]; counter++);
    return (counter);
}