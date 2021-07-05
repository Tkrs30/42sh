/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-hugo.gardes
** File description:
** chained.c
*/

#include <unistd.h>
#include "../include/include.h"
#include "../include/include2.h"

void find_path(char **path, char *command, char **tab, char **env)
{
    for (int i = 1; path[i] != NULL; i++) {
        path[i] = concat_strings(path[i], "/");
        path[i] = concat_strings(path[i], command);
        if (!access(path[i], F_OK)) {
            execve(path[i], &tab[0], env);
        }
    }
}

char **get_path(test_env *test, char *search, int len)
{
    int size = test->size;
    test_env *save = test;
    char **path = NULL;
    for (int u = 0; u < size && nmatch(test->var_env, search, len); u++)
        test = test->next;
    path = my_str_t_w_a(test->var_env, "=:");
    test = save;
    return (path);
}

void find_lunch(char **av, char **env)
{
    test_env *test = fill(env);
    char *command = av[0];
    char **path = get_path(test, "PATH=", 5);
    find_path(path, command, av, env);
    exit(84);
}

int my_strcmp(char *str_to_comp, char *comp)
{
    int u = 0;
    for (; comp[u]; u++)
        if (str_to_comp[u] != comp[u])
            return (1);
    if (str_to_comp[u] != 0)
        return (1);
    return (0);
}