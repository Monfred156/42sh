/*
** EPITECH PROJECT, 2019
** exit.c
** File description:
** ncauet
*/

#include <unistd.h>
#include <my.h>
#include <stdlib.h>
#include <function.h>

int look_around_exit(char **commands)
{
    int exit_value;
    int place = check_exit_command_exist(commands);

    if (place == -1)
        return (-1);
    if (commands[place + 1] != NULL && commands[place + 1][0] == '|')
        return (-2);
    exit_value = check_exit_value(commands[place]);
    if (exit_value == -1)
        return (-1);
    return (exit_value);
}

int check_error_exit(char *string)
{
    int count = 0;

    while (string[count] != '\0') {
        if (string[count] >= '0' && string[count] <= '9')
            count++;
        else {
            my_putstr_error("exit: Expression Syntax.\n");
            return (-1);
        }
    }
    close(0);
    return (atoi(string));
}

int check_exit_value(char *buf)
{
    int x = 0;
    int y = 4;
    int place = 0;
    char *string;

    while (my_strncmp(buf, "exit", 4) != 0)
        x++;
    while (buf[y] == ' ')
        y++;
    if (buf[y] == '\0')
        return (0);
    string = check_malloc_char(my_strlen(buf) - 4);
    while (buf[y] != '\0') {
        string[place] = buf[y];
        y++;
        place++;
    }
    string[place] = '\0';
    return (check_error_exit(string));
}

int check_exit_command_exist(char **commands)
{
    int x = 0;

    while (commands[x] != NULL && my_strncmp("exit", commands[x], 4) != 0)
        x++;
    if (commands[x] == NULL)
        return (-1);
    return (x);
}