/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/


#ifndef MY_H_
#define MY_H_

int my_str_isnum(char *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *int_to_str(int nb);
char *my_revstr(char *str);
char *my_int_to_str(int nb);
int my_strcmp(char const *s1, char const *s2);
char *get_next_line(int fd);
char *my_strdup(char *str);
char *my_realloc(char *string, int nb);
int array_len(char **array);
void my_put_nbr(int nb);
char *check_malloc_char(int size);
char **check_malloc_char_star(int size);
int *check_malloc_int(int size);
void my_put_nbr(int nb);
char **my_str_to_word_array(char *map, char *character);
char *my_str_copy(char *str);
char *add_chars_before_str(char *str, char *add);
char *add_chars_after_str(char *str, char *add);
void my_free(char **str);
int my_str_count(char *str, char *chr);
int my_strncmp(char const *, char const *, int);
char *my_strdup(char *str);
char *my_strcat(char *str1, char const *str2);
char **cpy_array(char **array);
void print_error_exec(char *str, char *error);
int detect_exec(char *str);
char **my_realloc_array(char **str, int nb);

#endif
