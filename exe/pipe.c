/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-hugo.gardes
** File description:
** pipe.c
*/

#include <include.h>

bool is_piped(char *str, char **env, int child)
{
    for (int u = 1; str[u + 1]; u++) {
        if (str[u] == '|' && str[u + 1] != '|' && str[u - 1] != '|') {
            return (true);
        } else if (str[u] == '|' && str[u + 1] == '|') {
            return (or_or(str, env, child));
        }
        if (str[u] == '&' && str[u + 1] == '&') {
            return (and_and(str, env, child));
        }
    }
    return (false);
}

int nbr_pipe(char *str, char c)
{
    int nbr = 0;

    for (int u = 0; str[u]; u++)
        if (str[u] == c)
            nbr += 1;
    return (nbr);
}

void clean_wait(int child, int nbr)
{
    int nique = 0;

    for (int u = 0; u < nbr; u++)
        wait(&nique);
    if (!child)
        exit(0);
}

void reduct_pipe(int *piped, int i, int nbr)
{
    if (i != 0)
        dup2(piped[(i - 1) * 2], STDIN_FILENO);
    if (i != nbr)
        dup2(piped[i * 2 + 1], STDOUT_FILENO);
    for (int o = 0; o < nbr * 2; o++)
        close(piped[o]);
}

bool pipe_funct(char *str, char **env, int child)
{
    int nbr = nbr_pipe(str, '|');

    if (is_piped(str, env, child)) {
        reduc_main_pipe(child, str, env, nbr);
        clean_wait(child, nbr);
        return (true);
    }
    return (false);
}