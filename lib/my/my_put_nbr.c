/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** oui
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb <= 9) {
        if (nb < 0) {
            nb = nb * (-1);
            my_putchar('-');
            my_put_nbr(nb);
            return (0);
        }
    } else if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
}
