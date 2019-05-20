/*
** EPITECH PROJECT, 2019
** space_in_str
** File description:
** space_in_str.c
*/

#include "my.h"
#include "function.h"

int malloc_nbr_string(char *string)
{
    int counter = 0;

    for (int i = 0; string[i]; i++)
        if (string[i] == ' ')
            counter++;
    return (counter+2);
}

int check_separator(char charca)
{
    if (charca == '|')
        return 1;
    if (charca == '&')
        return 1;
    return 0;
}

char *set_separator(char *string, int *i)
{
    char *tmp = malloc(sizeof(char) * 3);
    int j = 0;

    for (;string[*i] != '\0' && string[*i] != ' '; i++) {
        tmp[j]= string[*i];
        j++;
    }
    tmp[j] = '\0';
    return tmp;
}

char **parse_string(char *string)
{
    char **array = malloc(sizeof(char *) * malloc_nbr_string(string));
    int n  = 0;
    int m = 0;

    array[m] = malloc(sizeof(char) * (strlen(string) + 1));
    for (int i = 0; string[i]; i++) {
        if (string[i] == '>' || string[i] == '<') {
            array[m][n] = '\0';
            m++;
            array[m] = malloc(sizeof(char) * (strlen(string) + 1));
            n = 0;
            for (; string[i] != '\0' && string[i] != ' '; i++) {
                array[m][n] = string[i];
                n++;
            }
            array[m][n] = ' ';
            n++;
            i++;
            for (; string[i] != '\0' && string[i] != ' '; i++) {
                array[m][n] = string[i];
                n++;
            }
            array[m][n] = '\0';
            m++;
            array[m] = malloc(sizeof(char) * (strlen(string) + 1));
            n = 0;
        } else if (check_separator(string[i]) == 1) {
            array[m][n] = '\0';
            array[m+1] = malloc(sizeof(char) * (strlen(string) + 1));
            n = 0;
            for (; string[i] != '\0' && string[i] != ' '; i++) {
                array[m+1][n] = string[i];
                n++;
            }
            array[m+1][n] = '\0';
            m+=2;
            array[m] = malloc(sizeof(char) * (strlen(string) + 1));
            n = 0;
        } else {
            array[m][n] = string[i];
            n++;
        }
    }
    array[m][n] = '\0';
    array[m+1] = NULL;
    return array;
}
