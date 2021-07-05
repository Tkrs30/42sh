/*
** EPITECH PROJECT, 2020
** bsminishell
** File description:
** ms_len.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/include.h"
#include "../include/include2.h"

int ms_len_re(char *str)
{
    int size = 0;
    for (; str[size]; size++);
    return (size);
}

int my_getline(char **str, size_t len)
{
    if (isatty(STDIN_FILENO) == 1)
        write(1, "$> ", 3);
    return (getline(str, &len, stdin));
}