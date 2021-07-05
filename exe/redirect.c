/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-hugo.gardes
** File description:
** redirect.c
*/

#include "../include/include.h"

void select_dup(char *str, int *dup__)
{
    int i = 0;
    for (; str[i] != '>' && str[i]; i++);
    i--;
    if (str[i] == '1' || str[i] == '2')
        *dup__ = str[i] - 48;
    else
        *dup__ = 1;
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*') {
        str[i] = '\t';
    }
}

bool is_redirect(char *str, int *dup__)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '>') {
            select_dup(str, dup__);
            return (true);
        }
        if (str[i] == '<')
            exit(0);
    }
    return (false);
}

bool is_dooble(char *str)
{
    for (int i = 0; str[i + 1]; i++) {
        if (str[i] == '>' && str[i + 1] == '>')
            return (true);
    }
    return (false);
}

void select_fd(int *fd, char *str, char **arg_temp)
{
    if (is_dooble(str)) {
        *fd = open(arg_temp[0], O_RDWR | O_APPEND);
    } else {
        *fd = open(arg_temp[0], O_RDWR | O_TRUNC);
        close(*fd);
        *fd = open(arg_temp[0], O_RDWR);
    }
    if (*fd == -1)
        *fd = open(arg_temp[0], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
}

bool redirect(char *str, char **env, pid_t child)
{
    int fd;
    char **arg = NULL;
    char **arg_temp = NULL;
    int dup__ = 1;
    if (is_redirect(str, &dup__)) {
        arg = my_str_t_w_a(str, ">\t");
        arg_temp = my_str_t_w_a(arg[1], " ");
        if (child == 0) {
            select_fd(&fd, str, arg_temp);
            dup2(fd, dup__);
            close(fd);
            main(999, arg, env);
            exit(0);
            close(fd);
        }
        return (true);
    }
    return (false);
}