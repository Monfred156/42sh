/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char *str)
{
    if ((str[0] != '-' && (str[0] < 48 || str[0] > 57)) ||
    (str[0] == '-' && str[1] == '\0'))
        return (1);
    for (int i = 1; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (1);
    return (0);
}