/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;

    while ((s1[count] != '\0' || s2[count] != '\0') && count < n) {
        if (s1[count] == s2[count])
            count++;
        else
            return (84);
    }
    return (0);
}
