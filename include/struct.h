/*
** EPITECH PROJECT, 2018
** struct
** File description:
** .h
*/

#ifndef PSU_42SH_2018_STRUCT_H
#define PSU_42SH_2018_STRUCT_H

#include <stdbool.h>

#define VALID 0
#define ERROR 1

typedef struct s_data {
    char **cpy_env;
    char **old_pwd;
    int to_return;
    bool finish;
} data_t;

#endif //PSU_42SH_2018_STRUCT_H
