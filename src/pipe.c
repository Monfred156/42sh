/*
** EPITECH PROJECT, 2019
** pipe
** File description:
** pipe.c
*/

#include <zconf.h>
#include "function.h"

void first_pipe(int *inout_put, int *pipefd)
{
    pipe(pipefd);

    inout_put[1] = pipefd[1];
}

void middle_pipe(int *inout_put, int *pipefd)
{
    int save = pipefd[0];

    close(pipefd[1]);
    pipe(pipefd);
    inout_put[0] = save;
    inout_put[1] = pipefd[1];
}

void last_pipe(int *inout_put, int *pipefd)
{
    close(pipefd[1]);
    inout_put[0] = pipefd[0];
}