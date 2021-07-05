/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-navy-hugo.gardes
** File description:
** get_number.c
*/

#include <stdarg.h>
#include "../include.h"

void get_nbr(va_list ap, char *buff)
{
    int *i = va_arg(ap, int *);
    *i = my_getnbr(buff);
}