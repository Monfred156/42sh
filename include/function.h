/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** function.h
*/

#ifndef PSU_42SH_2018_FUNCTION_H
#define PSU_42SH_2018_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

///history.c///
char **get_history(char **history, char *str);
void print_history(char **history);

///space_in_str///
char *space_in_str(char *str);

///42sh.c///
int main_42sh(void);

#endif //PSU_42SH_2018_FUNCTION_H
