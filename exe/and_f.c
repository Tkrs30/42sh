/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** and_f.c
*/

#include <include.h>

bool check_is_continue_and(int check)
{
    int gevaudant = 0;
    if (WIFEXITED(check)) {
        gevaudant = WEXITSTATUS(check);
        if (gevaudant != 84) {
            return (true);
        }
    }
    return (false);
}

bool and_and(char *str, char **env, int child)
{
    bool is_continue = true;
    char **tab_arg = my_str_t_w_a(str, "&");
    pid_t pid = 0;
    int check;
    if (child == 0)
        exit(84);
    for (int u = 0; tab_arg[u] && is_continue; u++) {
        is_continue = true;
        pid = fork();
        if (pid == 0) {
            main(999, &tab_arg[u], env);
            exit(84);
        }
        wait(&check);
        is_continue = check_is_continue_and(check);
    }
    return (false);
}