/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int counter = 0;
    for (; str[counter]; counter++);
    return (counter);
}
