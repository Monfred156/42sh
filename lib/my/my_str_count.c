/*
** EPITECH PROJECT, 2019
** my_str_count
** File description:
** compte le nombre de x charactère dans un char *
*/

int count_chr(char str, char *chr)
{
    for (int nb = 0; chr[nb] != 0; nb++)
        if (str == chr[nb])
            return (1);
    return (0);
}

int my_str_count(char *str, char *chr)
{
    int count = 0;

    for (int nb = 0; str[nb] != 0; nb++)
        count += count_chr(str[nb], chr);
    return (count);
}