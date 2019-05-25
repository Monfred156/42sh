/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** function.h
*/

#ifndef PSU_42SH_2018_FUNCTION_H
#define PSU_42SH_2018_FUNCTION_H

#include "my.h"
#include "struct.h"
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
#include <signal.h>
#include <stdbool.h>

///history.c///
char **get_history(char **history, char *str);
void print_history(char **history);

///str_clean.c///
char *str_clean(char *str);
char *str_and_or(char *copy, char *str, int *nb);
char *str_simple_char(char *copy, char *str, int *nb);
char *del_to_much_space(char *str);
char *str_direction(char *copy, char *str, int *nb);

///42sh.c///
int main_42sh(char **env);

///get_env.c///
void get_env(char **env, data_t *data);

///parse_string.c///
char **parse_string(char *string);
char **clean_array(char **array);
int check_separator(char charca);

///remove_n.c///
char *remove_n(char *string);

///shell_excve.c///
int excve_function(char **argv, data_t *data);

///search_function.c///
int search_builtin_function(char *str, data_t *data, int *inout_put);

///file_array_pars.c///
int fill_array_after_separa(const char *string, char **array, int *rank, int i);
int fill_array_after_redir(const char *string, char **array, int *rank, int i);

///exit.c///
int check_exit_command_exist(char **commands);
int check_exit_value(char *commands);
int look_around_exit(char **commands);

///error_handling.c///
int check_error(char *string);
int string_is_sep_no_redir(char *string);
int string_is_separator(char *string);
int string_is_redir(char *string);
int ambigous_redirect(char **array, int i);
int check_invalid_command(char **array);

///replace_environnement_var.c///
char **replace_environnement_var(char **array, data_t *data, bool *detec);


///and_or_function.c///
int and_function(char *str, char **env, int result);
int or_function(char *str, char **env, int result);

///free.c///
void free_char_double_star(char **array);

///all_redir.c///
bool check_redir_and_path(char **array, int *inout, int i);

///parser_and_or_semicolon.c///
void get_str(char **cmd_parsed, data_t *data);

///get_array_from_and_or_final.c///
int get_array_from_and_or_final(data_t *data, char **array);

///pipe.c///
void first_pipe(int *inout_put, char **array);
void middle_pipe(int *inout_put, char **array);
void last_pipe(int *inout_put, char **array);

///create_argv.c///
char **create_argv(char *str);
int search_param(char *str);

///env.c///
void print_env(char **cpy_env);

///setenv.c///
int check_setenv(char **array, data_t *data);
int check_arg(char **array, data_t *data, int count);

///unsetenv.c///
int check_unsetenv(char **array, data_t *data);

///cd.c///
int check_cd(char **array, data_t *data);

///cd_minus.c///
int algo_cd_first(data_t *data, int *count);
char *recup_old_pwd(char **cpy_env);
int recup_pwd(char **cpy_env);

#endif //PSU_42SH_2018_FUNCTION_H
