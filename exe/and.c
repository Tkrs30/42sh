/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-hugo.gardes
** File description:
** pipe.c
*/

#include "include.h"

bool is_and(char *str)
{
    bool is_string = false;
    for (int u = 0; str[u]; u++) {
        if (str[u] == ';' && !is_string) {
            return (true);
        }
        if (str[u] == '"' && !is_string) {
            is_string = true;
        } else if (str[u] == '"' && is_string)
            is_string = false;
    }
    return (false);
}

bool match_str(char *str, char *str_to_comp)
{
    if (my_strlen(str) != my_strlen(str_to_comp))
        return (false);
    for (int i = 0; str[i]; i++)
        if (str[i] != str_to_comp[i])
            return (false);
    return (true);
}

void reduct_and(char **tab, int i, char **env)
{
    pid_t pid = 0;
    int nique = 0;
    pid = fork();
    waitpid(pid, &nique, 0);
    if (pid == 0) {
        main(999, &tab[i], env);
        exit(0);
    }
}

bool and_funct(char *argv, char **env, int child)
{
    char **tab = NULL;
    int nique = 0;

    if (is_and(argv)) {
        tab = my_str_t_w_a(argv, ";");
        waitpid(child, &nique, 0);
        for (int i = 0; child == 0 && tab[i]; i++) {
            reduct_and(tab, i, env);
        }
        if (child == 0)
            exit(0);
        return (true);
    }
    return (false);
}