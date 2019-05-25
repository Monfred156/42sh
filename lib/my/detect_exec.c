/*
** EPITECH PROJECT, 2019
** detect_exec
** File description:
** detect_exec.c
*/

int detect_exec(char *str)
{
    if (str[0] == '.' && str[1] == '/')
        return (1);
    for (int nb = 0; str[nb + 2] != '\0'; nb++)
        if (str[nb] != '.' && str[nb + 1] == '.' && str[nb + 2] == '/')
            return (1);
    return (0);
}