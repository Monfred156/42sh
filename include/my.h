/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/


#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *int_to_str(int nb);
char *my_revstr(char *str);
char *my_int_to_str(int nb);
int my_strcmp(char const *s1, char const *s2);
char *get_next_line(int fd);
char *my_strdup(char *str);
char *my_realloc(char *string, int nb);
char *add_chars_to_str(char *str, char *characteres);
int array_len(char **array);
void my_put_nbr(int nb);
char **my_str_to_word_array(char *str);
char *check_malloc_char(int size);
char **check_malloc_char_star(int size);
int *check_malloc_int(int size);

#endif
